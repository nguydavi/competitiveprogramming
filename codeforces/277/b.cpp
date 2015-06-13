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
const int MAXM = 110;
int M, N;
int mat[MAXM][MAXN], res[MAXM][MAXN];

int main() {
    scanf("%d %d", &M, &N); 
    memset(res, -1, sizeof(res));
    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j) {
            scanf("%d", &mat[i][j]);

            if(!mat[i][j]) {
                for(int r=0;r<M;++r)
                    res[r][j] = 0;
                for(int c=0;c<N;++c)
                    res[i][c] = 0;
            }
        }

    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j)
            if(res[i][j] == -1)
                res[i][j] = 1;
    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j) {
            int test = 0;
            for(int r=0;r<M;++r)
                test |= res[r][j];
            for(int c=0;c<N;++c)
                test |= res[i][c];

            if(test != mat[i][j]) {
                printf("NO\n");
                return 0;
            }
        }


    printf("YES\n");
    for(int i=0;i<M;++i) {
        printf("%d", res[i][0]);
        for(int j=1;j<N;++j)
            printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}
