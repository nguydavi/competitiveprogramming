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

const int MAXN = 3e4+10;
const int MAXDIFF = 300;
int N, D, maxD;
map<int, int> gems;

int dp[MAXN][2*MAXDIFF];

/**
 * Store difference of jump length with D because much smaller.
 * Difference can be up (or down) to ~250 from D (because 250*251/2 ~= 30000)
 * Store difference [-300;300] shifted to [0;600]
 */
int solve(int cur, int len) {
    if(cur > maxD)
        return 0;
    if(dp[cur][len-D+MAXDIFF] != -1)
        return dp[cur][len-D+MAXDIFF];

    int res = solve(cur+len, len);
    res = max(res, solve(cur+len+1, len+1));
    if(len-1 > 0)
        res = max(res, solve(cur+len-1, len-1));

    if(gems.find(cur) != gems.end())
        res += gems[cur];

    dp[cur][len-D+MAXDIFF] = res;
    return res;
}

int main() {
    scanf("%d %d", &N, &D);
    maxD = 0;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;++i) {
        int g;
        scanf("%d", &g);
        ++gems[g];
        maxD = max(maxD, g);
    }
    printf("%d\n", solve(D, D));
    return 0;
}
