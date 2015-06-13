#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 10;
const int MAXK = 110;
const int INF = (int)1e9;
int N, K;
int liftTime[MAXN];
bool liftFloor[MAXN][MAXK];
vector<vector<pii> > adjList;

int solve() {
    int res = INF;
    for(int lift=0;lift<N;++lift) {
        vector<int> dist(N*MAXK, INF);
        dist[lift*MAXK] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(pii(0, lift*MAXK));

        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            int u = cur.second;
            int d = cur.first;
            
            if(d <= dist[u])
                for(int i=0;i<adjList[u].size();++i) {
                    pii nxt = adjList[u][i];
                    int v = nxt.first;
                    int vd = nxt.second;
                    if(dist[u] + vd < dist[v]) {
                        dist[v] = dist[u] + vd;
                        pq.push(pii(dist[v], v));
                    }
                }
        }

        for(int i=0;i<N;++i)
            res = min(res, dist[i*MAXK+K]);
    }
    return res;
}

int main() {
    while(scanf("%d %d", &N, &K) == 2) {
        for(int i=0;i<N;++i)
            scanf("%d", &liftTime[i]);
        cin.ignore();
        memset(liftFloor, false, sizeof(liftFloor));
        for(int i=0;i<N;++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            int floor;
            while(ss >> floor)
                liftFloor[i][floor] = true;
        }

        adjList.assign(N*MAXK, vector<pii>());
        for(int lift=0;lift<N;++lift)
            for(int i=0;i<MAXK;++i)
                for(int j=i+1;j<MAXK;++j)
                    if(liftFloor[lift][i] && liftFloor[lift][j]) {
                        int diff = abs(i-j);
                        adjList[lift*MAXK+i].push_back(pii(lift*MAXK+j, diff*liftTime[lift]));
                        adjList[lift*MAXK+j].push_back(pii(lift*MAXK+i, diff*liftTime[lift]));
                    }
        for(int lift1=0;lift1<N;++lift1)
            for(int lift2=lift1+1;lift2<N;++lift2)
                for(int i=0;i<MAXK;++i)
                    if(liftFloor[lift1][i] && liftFloor[lift2][i]) {
                        adjList[lift1*MAXK+i].push_back(pii(lift2*MAXK+i, 60));
                        adjList[lift2*MAXK+i].push_back(pii(lift1*MAXK+i, 60));
                    }

        int ans = solve();
        if(ans == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
