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
int N, R;
int dist[MAXN][MAXN];
int X, Y;

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d", &N, &R);
        memset(dist, 0, sizeof(dist));
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(i!=j)
                    dist[i][j] = INF;

        for(int i=0;i<R;++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            dist[u][v] = dist[v][u] = 1;
        }

        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        scanf("%d %d", &X, &Y);
        int ans = 0;
        for(int i=0;i<N;++i)
            ans = max(ans, dist[X][i] + dist[i][Y]);

        printf("Case %d: %d\n", ii, ans);
    }
    return 0;
}
