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

typedef long long ll;
const int MAXN = (int)1e5+10;
int N, M;
vector<vector<int> > adjList;
int dist[MAXN];

int diam;
int farthest;

/**
 * For each query we take the distance from the node to one of the diameter node (the farthest one)
 * which is the largest distance from any node and add (K-1) the diameter.
 *
 * Note: 3rd dfs() is necessary to update the distance to the farthest found in
 * first dfs
 */
void dfs(int cur, int prev, int d) {
    dist[cur] = max(dist[cur], d);
    if(diam < d) {
        diam = d;
        farthest = cur;
    }

    for(int i=0;i<adjList[cur].size();++i) {
        int v = adjList[cur][i];
        if(v != prev)
            dfs(v, cur, d+1);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    adjList.assign(N, vector<int>());
    for(int i=0;i<N-1;++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    diam = 0;
    farthest = 0;
    memset(dist, 0, sizeof(dist));
    dfs(farthest, -1, 0);
    dfs(farthest, -1, 0);
    dfs(farthest, -1, 0);

    while(M--) {
        int v, k;
        scanf("%d %d", &v, &k);
        --v;
        ll ans = 0LL + dist[v] + 1LL*(k-1)*diam;
        printf("%lld\n", ans);
    }

    return 0;
}
