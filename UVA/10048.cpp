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
int N, M, Q;
int dist[MAXN][MAXN];

int main() {
    int tc = 0;
    while(scanf("%d %d %d", &N, &M, &Q) == 3 && (N || M || Q)) {
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                dist[i][j] = INF;
        for(int i=0;i<M;++i) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            --u;
            --v;
            dist[u][v] = dist[v][u] = z;
        }

        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));

        if(tc)
            printf("\n");
        printf("Case #%d\n", ++tc);
        while(Q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a;
            --b;
            if(dist[a][b] == INF)
                printf("no path\n");
            else
                printf("%d\n", dist[a][b]);
        }
    }    
    return 0;
}
