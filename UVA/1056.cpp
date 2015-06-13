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

const int MAXN = 60;
const int INF = (int)1e9;
int N, R;
int dist[MAXN][MAXN];
map<string, int> mm;

int main() {
    int tc = 0;
    while(scanf("%d %d", &N, &R) == 2 && (N || R)) {
        mm.clear();
        int cur = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(i!=j)
                    dist[i][j] = INF;
                else
                    dist[i][j] = 0;

        for(int i=0;i<R;++i) {
            string a, b;
            cin >> a >> b;
            if(mm.find(a) == mm.end())
                mm[a] = cur++;
            if(mm.find(b) == mm.end())
                mm[b] = cur++;

            dist[mm[a]][mm[b]] = dist[mm[b]][mm[a]] = 1;
        }

        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int ans = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                ans = max(ans, dist[i][j]);

        if(ans == INF)
            printf("Network %d: DISCONNECTED\n\n", ++tc);
        else
            printf("Network %d: %d\n\n", ++tc, ans);

    } 
    return 0;
}
