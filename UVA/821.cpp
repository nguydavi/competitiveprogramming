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
int dist[MAXN][MAXN];

int main() {
    int tc = 1;
    int u, v;
    while(scanf("%d %d", &u, &v) && u && v) {
        memset(dist, 0, sizeof(dist));
        for(int i=0;i<MAXN;++i)
            for(int j=0;j<MAXN;++j)
                if(i != j)
                    dist[i][j] = INF;

        dist[u][v] = 1;
        while(scanf("%d %d", &u, &v) && u && v)
            dist[u][v] = 1;

        for(int k=0;k<MAXN;++k)
            for(int i=0;i<MAXN;++i)
                for(int j=0;j<MAXN;++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int sum = 0;
        int total = 0;
        for(int i=0;i<MAXN;++i)
            for(int j=0;j<MAXN;++j)
                if(dist[i][j] < INF && dist[i][j])
                    sum += dist[i][j], ++total;

        printf("Case %d: average length between pages = %.3lf clicks\n", tc++, 1.*sum/total);
    }
    return 0;
}
