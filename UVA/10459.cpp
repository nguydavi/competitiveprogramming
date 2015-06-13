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

const int MAXN = 5010;
const int INF = (int)1e9;
int N;
vector<vector<int> > adjList;
int dist[MAXN];

int maxDist;
int cur;

/**
 * We do 3 dfs keeping the biggest distance for each node, going from the worst for each dfs.
 * From the first dfs after we find the furthest node, we dfs from it and the path to the furthest 
 * from it is a diameter. We do a last dfs from that last node as the worst nodes from the first dfs 
 * do not have the worst distance yet.
 * 
 * The nodes with the min dist are then centers (there are at most 2, depending on parity of length of diameter)
 */
void dfs(int u, int prev, int d) {
    dist[u] = max(dist[u], d);
    if(maxDist < dist[u]) {
        cur = u;
        maxDist = dist[u];
    }

    for(int i=0;i<adjList[u].size();++i) {
        int v = adjList[u][i];
        if(v != prev)
            dfs(v, u, d+1);
    }
}

int main() {
    while(scanf("%d", &N) == 1) {
        adjList.assign(N, vector<int>());
        for(int i=0;i<N;++i) {
            int m;
            scanf("%d", &m);
            while(m--) {
                int v;
                scanf("%d", &v);
                --v;
                adjList[i].push_back(v);
            }
        }

        memset(dist, -1, sizeof(dist));
        maxDist = 0;
        cur = 0;
        dfs(cur, -1, 0);
        dfs(cur, -1, 0);
        dfs(cur, -1, 0);
        
        int minDist = INF;
        for(int i=0;i<N;++i)
            minDist = min(minDist, dist[i]);

        printf("Best Roots  :");
        for(int i=0;i<N;++i)
            if(dist[i] == minDist)
                printf(" %d", i+1);
        printf("\n");
        printf("Worst Roots :");
        for(int i=0;i<N;++i)
            if(dist[i] == maxDist)
                printf(" %d", i+1);
        printf("\n");
    }

    return 0;
}
