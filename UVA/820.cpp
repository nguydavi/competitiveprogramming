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

const int MAXN = 110;
const int INF = (int)1e9;
int N, S, T, C;
int adj[MAXN][MAXN];
vector<int> prev;

int augment(int v, int minEdge) {
    if(v == S)
        return minEdge;

    if(prev[v] != -1) {
        int f = augment(prev[v], min(minEdge, adj[prev[v]][v]));
        adj[prev[v]][v] -= f;
        adj[v][prev[v]] += f;
        return f;
    }
    return 0;
}

int solve() {
    int res = 0;
    while(true) {
        prev.assign(N, -1);
        vector<int> dist(N, INF);
        dist[S] = 0;
        queue<int> q;
        q.push(S);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u == T)
                break;
            for(int v=0;v<N;++v)
                if(adj[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    prev[v] = u;
                }
        }
        int f = augment(T, INF);
        if(f == 0)
            break;
        res += f;
    }
    return res;
}

int main() {
    int tc = 1;
    while(scanf("%d", &N) == 1 && N) {
        memset(adj, 0, sizeof(adj));
        scanf("%d %d %d", &S, &T, &C);
        --S, --T;
        while(C--) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            --u, --v;
            adj[u][v] += z;
            adj[v][u] += z;
        }
        
        int ans = solve();
        printf("Network %d\n", tc++);
        printf("The bandwidth is %d.\n\n", ans);
    }
    return 0;
}
