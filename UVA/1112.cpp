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
const int MAXN = 110;
const int INF = (int)1e9;
int N, E, T, M;
vector<vector<pii> > adjList;
vector<int> dist;

int solve(int u) {
    dist.assign(N, INF);
    dist[u] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, u));

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int v = cur.second;
        int d = cur.first;
        if(d <= dist[v])
            for(int i=0;i<adjList[v].size();++i) {
                pii k = adjList[v][i];
                if(dist[v] + k.second < dist[k.first]) {
                    dist[k.first] = dist[v] + k.second ;
                    pq.push(pii(dist[k.first], k.first));
                }
            }
    }
    return dist[E];
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d %d", &N, &E, &T, &M);
        --E;
        adjList.assign(N, vector<pii>());
        for(int i=0;i<M;++i) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            --u, --v;
            adjList[u].push_back(pii(v, z));
        }

        int ans = 0;
        for(int i=0;i<N;++i) {
            if(solve(i) <= T)
                ++ans;
        }

        printf("%d\n", ans);
        if(tc)
            printf("\n");
    }
    return 0;
}
