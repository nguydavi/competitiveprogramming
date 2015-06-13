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

const int MAXN = 210;
const int INF = (int)1e9;
int N, M, Q;
int busy[MAXN];
vector<vector<int> > adjList;
vector<int> dist;

int cube(int x) {
    return x*x*x;
}

void solve() {
    dist.assign(N, INF);
    dist[0] = 0;

    for(int i=0;i<N-1;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<adjList[j].size();++k) {
                int v = adjList[j][k];
                if(dist[j] < INF)
                    dist[v] = min(dist[v], dist[j] + cube(busy[v] - busy[j]));
            }
    for(int j=0;j<N;++j)
        for(int k=0;k<adjList[j].size();++k) {
            int v = adjList[j][k];
            if(dist[j]+cube(busy[v]-busy[j]) < dist[v])
                dist[v] = -INF;
        }
}

int main() {
    int tc = 1;
    while(scanf("%d", &N) == 1) {
        adjList.assign(N, vector<int> ());
        for(int i=0;i<N;++i)
            scanf("%d", &busy[i]);
        scanf("%d", &M);
        for(int i=0;i<M;++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
        }
        solve();

        printf("Set #%d\n", tc++);
        scanf("%d", &Q);
        for(int i=0;i<Q;++i) {
            int q;
            scanf("%d", &q);
            --q;
            int ans = dist[q];
            if(ans < 3 || ans == INF)
                printf("?\n");
            else
                printf("%d\n", ans);
        }
    }
    return 0;
}
