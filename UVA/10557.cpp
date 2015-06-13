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
int N, M;
vector<vector<int> > adjList;
int energy[MAXN];

bool vis[MAXN];

bool dfs(int s, int e) {
    vis[s] = true;
    if(s == e)
        return true;

    bool res = false;
    for(int i=0;i<adjList[s].size();++i) {
        if(!vis[adjList[s][i]])
            res |= dfs(adjList[s][i], e);
    }
    return res;
}

bool solve() {
    vector<int> dist(N, -INF);
    dist[0] = 100;

    for(int i=0;i<N-1;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<adjList[j].size();++k) {
                int v = adjList[j][k];
                if(dist[j] > -INF && dist[j]+energy[v] > 0)
                    dist[v] = max(dist[v], dist[j] + energy[v]);
            }

    bool hasPosCycle = false;
    for(int j=0;j<N;++j)
        for(int k=0;k<adjList[j].size();++k) {
            int v = adjList[j][k];
            if(dist[v] > -INF && dist[j]+energy[v] > dist[v]) {
                memset(vis, false, sizeof(vis));
                bool b1 = dfs(0, v);
                memset(vis, false, sizeof(vis));
                bool b2 = dfs(v, N-1);
                hasPosCycle = b1 && b2;
            }
        }
    return dist[N-1] > 0 || hasPosCycle;
}

int main() {
    while(scanf("%d", &N) == 1 && N != -1) {
        adjList.assign(N, vector<int>());
        for(int i=0;i<N;++i) {
            scanf("%d", &energy[i]);
            scanf("%d", &M);
            while(M--) {
                int v;
                scanf("%d", &v);
                --v;
                adjList[i].push_back(v);
            }
        }
        bool ans = solve();
        if(ans)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}
