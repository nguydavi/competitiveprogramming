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
const int MAXN = 20010;
const int INF = (int)1e9;
int N, M, S, T;
vector<vector<pii> > adjList;

int solve() {
    vector<int> dist(N, INF);
    dist[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, S));

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.second;
        int d = cur.first;
        if(d <= dist[u]) {
            for(int i=0;i<adjList[u].size();++i) {
                pii nxt = adjList[u][i];
                int v = nxt.first;
                int vd = nxt.second;
                if(dist[u]+vd < dist[v]) {
                    dist[v] = dist[u] + vd;
                    pq.push(pii(dist[v], v));
                }
            }
        }
    }

    return dist[T];
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d %d", &N, &M, &S, &T);
        adjList.assign(N, vector<pii>());
        while(M--) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            adjList[u].push_back(pii(v, z));
            adjList[v].push_back(pii(u, z));
        }
        int ans = solve();
        if(ans != INF)
            printf("Case #%d: %d\n", ii, ans);
        else
            printf("Case #%d: unreachable\n", ii);
    }
    return 0;
}
