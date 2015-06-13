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

const int MAXN = 50;
const int INF = (int)1e9;
int N, M;
int distYoung[MAXN][MAXN];
int distOld[MAXN][MAXN];
char X, Y;

int main() {
    while(scanf("%d", &M) && M) {
        memset(distYoung, 0, sizeof(distYoung));
        memset(distOld, 0, sizeof(distOld));
        for(int i=0;i<MAXN;++i)
            for(int j=0;j<MAXN;++j)
                if(i!=j)
                    distYoung[i][j] = distOld[i][j] = INF;

        for(int i=0;i<M;++i) {
            char age, type, u, v;
            int energ;
            scanf(" %c %c %c %c %d", &age, &type, &u, &v, &energ);

            u -= 'A';
            v -= 'A';
            if(u == v)
                continue;

            if(age == 'Y')
                if(type == 'U')
                    distYoung[u][v] = energ;
                else
                    distYoung[u][v] = distYoung[v][u] = energ;
            else
                if(type == 'U')
                    distOld[u][v] = energ;
                else
                    distOld[u][v] = distOld[v][u] = energ;
        }
        scanf(" %c %c", &X, &Y);
        X -= 'A';
        Y -= 'A';

        for(int k=0;k<MAXN;++k)
            for(int i=0;i<MAXN;++i)
                for(int j=0;j<MAXN;++j) {
                    distYoung[i][j] = min(distYoung[i][j], distYoung[i][k] + distYoung[k][j]);
                    distOld[i][j] = min(distOld[i][j], distOld[i][k] + distOld[k][j]);
                }

        int energy = INF;
        for(int i=0;i<MAXN;++i)
            if(distYoung[X][i] + distOld[Y][i] < energy)
                energy = distYoung[X][i] + distOld[Y][i];

        if(energy == INF)
            printf("You will never meet.\n");
        else {
            printf("%d", energy);
            for(int i=0;i<MAXN;++i)
                if(distYoung[X][i] + distOld[Y][i] == energy)
                    printf(" %c", i+'A');
            printf("\n");
        }
    } 
    return 0;
}
