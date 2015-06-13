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

#define MAXN 13
#define MAXx 110
#define MAXT 23
#define MAXK 110
int N, x, T, K;
int price[MAXK], val[MAXK];
int dp[2*MAXK][2*MAXN][MAXx*MAXN];
//int dp[2*MAXN][MAXx*MAXN];

int tax(int x) {
    x *= 11;
    if (x%10 == 0) return x/10;
    else return (x/10)+1;
}

double solve() {
    memset(dp, 0, sizeof(dp));
    //double maxPrice = x*(N+1)/1.1 - T*(N+1);
    double maxPrice = x*(N+1);
    for(int j=1;j<=2*K;++j)
        for(int p=0;p<=maxPrice;++p)
            for(int k=1;k<=2*(N+1);++k) {
                int dimsum = (j-1)%K;
                if(price[dimsum] <= p)
                    dp[j][k][p] = max(dp[j-1][k][p], dp[j-1][k-1][p-price[dimsum]] + val[dimsum]);
                else
                    dp[j][k][p] = dp[j-1][k][p];
            }
    /*
     for (int i = 0; i < (2*K); ++i)
        for (int j = maxPrice; j >= price[i%K]; --j)
            for (int k = 1; k <= 2*(N+1); ++k)
                dp[k][j] = max(dp[k][j], dp[k-1][j-price[i%K]] + val[i%K]);
    */

    int ans = 0;
    for(int i=maxPrice;i>=0;--i) {
        if(tax(i+T*(N+1)) <= x*(N+1)) {
            //ans = dp[2*(N+1)][i];
            ans = dp[2*K][2*(N+1)][i];
            break;
        }
    }
    //return 1.0*dp[2*K][2*(N+1)][(int)maxPrice]/(N+1);
    return 1.0*ans/(N+1);
}

int main() {
    while(scanf("%d %d %d %d", &N, &x, &T, &K) && (N || x || T || K)) {
        memset(price, 0, sizeof(price));
        memset(val, 0, sizeof(val));
        for(int j=0;j<K;++j) {
            scanf("%d", &price[j]);
            for(int i=0;i<=N;++i) {//<= N+1 persons in total
                int newVal;
                scanf("%d", &newVal);
                val[j] += newVal;
            }
        }

        printf("%.2lf\n", solve());
    } 
    return 0;
}
