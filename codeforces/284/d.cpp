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
const int MAXT = 5010;
int N, T;
int prob[MAXN], tim[MAXN];

float dp[MAXT][MAXN][2];

// There is mistake somewhere, not sure what..
// Gets WA on pretest 6 :(
double solve(int t, int n, int curplay) {
    if(n == N || t == T+1)
        return 0;
    if(curplay >= tim[n] && dp[t][n][0] != -1)
        return dp[t][n][0];
    if(dp[t][n][1] != -1)
        return dp[t][n][1];
    
    double res;
    if(curplay >= tim[n]) {
        res = 1 + solve(t+1, n+1, 1);
        dp[t][n][0] = res;
    } else {
        res = prob[n]/100. * (1 + solve(t+1, n+1, 1));
        res += (100-prob[n])/100. * solve(t+1, n, curplay+1);
        dp[t][n][1] = res;
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &T);
    for(int i=0;i<N;++i)
        scanf("%d %d", &prob[i], &tim[i]);

    for(int i=0;i<=T+1;++i)
        for(int j=0;j<=N;++j)
            for(int k=0;k<2;++k)
                dp[i][j][k] = -1;

    double ans = solve(1, 0, 1);
    printf("%f\n", ans);

    return 0;
}
