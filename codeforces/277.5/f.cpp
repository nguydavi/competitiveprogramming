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

typedef long long ll;

const int MAXN = 510;
int N, M, mod;
int cnt[MAXN];
int dp[MAXN][MAXN];

int solve(int x, int y) {
    if(x == 0 && y == 0)
        return 1;
    if(dp[x][y] != -1)
        return dp[x][y];

    int res = 0;
    if(x > 1) { //add a one on two column with no ones
        ll ways = x * (x-1) / 2; ways %=mod;
        ways *= solve(x-2, y+2)%mod; ways %= mod;
        res += ways; res %= mod;
    }
    if(x >= 1 && y >= 1) { //add a one on a column with no ones and a one on a column with one one
        ll ways = x*y; ways %= mod;
        ways *= solve(x-1, y)%mod; ways %= mod; //solve(x-1, y) because y-1+1 (removing one from y but adding one because we removed one from x)
        res += ways; res %= mod;
    }
    if(y > 1) { //add a one on two column which have already one one
        ll ways = y * (y-1) / 2; ways %= mod;
        ways *= solve(x, y-2)%mod; ways%= mod;
        res += ways; res %= mod;
    }

    dp[x][y] = res;
    return res;
}

int main() {
    scanf("%d %d %d", &N, &M, &mod);
    memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j) {
            char c;
            scanf(" %c", &c);
            cnt[j] += c-'0';
        }

    int colNoOnes = 0;
    int colOneOnes = 0;
    for(int i=0;i<N;++i)
        if(cnt[i] == 1)
            ++colOneOnes;
        else if(!cnt[i])
            ++colNoOnes;

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(colNoOnes, colOneOnes));
    return 0;
}
