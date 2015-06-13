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
int N, M;

string a, b;
int dp[MAXN][MAXN];

int solve() {
    N = a.size();
    M = b.size();
    memset(dp, 0, sizeof(dp));

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j) {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j-1];

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    return dp[N][M];
}

int main() {
    int tc = 1;
    while(getline(cin, a) && a != "#" && getline(cin, b))
        printf("Case #%d: you can visit at most %d cities.\n", tc++, solve());
    return 0;
}
