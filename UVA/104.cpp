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

const int MAXN = 30;
int N;
double dist[MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN];

void printPath(int a, int b, int s) {
    if(path[a][b][s] == -1) {
        printf("%d %d", a+1, b+1);
        return;
    }

    printPath(a, path[a][b][s], s-1);
    printf(" %d", b+1);
}

int main() {
    while(scanf("%d", &N) == 1) {
        memset(path, -1, sizeof(path));
        memset(dist, 0 ,sizeof(dist));
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(i!=j)
                    scanf(" %lf", &dist[i][j][0]);
                else
                    dist[i][j][0] = 1;

        bool hasFound = false;
        for(int s=1;s<N;++s) {
            for(int k=0;k<N;++k)
                for(int i=0;i<N;++i)
                    for(int j=0;j<N;++j)
                        if(dist[i][k][s-1]*dist[k][j][0] > dist[i][j][s]) {
                            dist[i][j][s] = dist[i][k][s-1]*dist[k][j][0];
                            path[i][j][s] = k;
                        }

            for(int a=0;a<N;++a)
                if(dist[a][a][s] >= 1.01) {
                    printPath(a, a, s);
                    printf("\n");
                    hasFound = true;
                    break;
                }

            if(hasFound) {
                break;
            }
        }

        if(!hasFound)
            printf("no arbitrage sequence exists\n");

    }
    return 0;
}
