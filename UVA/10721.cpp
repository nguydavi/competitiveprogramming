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

const int MAXN = 55;
const int MAXK = 55;
const int MAXM = 55;
typedef long long ll;
int N, K, M;
ll dp[MAXN][MAXK][MAXM];

ll solve(int n, int k, int m) {
    if(n == N) { 
        if(k == K)
            return 1;
        return -1;
    }
    if(k > K)
        return -1;
    if(dp[n][k][m] != -1)
        return dp[n][k][m];

    ll res1 = m == M ? 0 : max(0LL, solve(n+1, k, m+1));
    ll res2 = max(0LL, solve(n+1, k+1, 1));

    return dp[n][k][m] = res1 + res2;
}

int main() {
    while(cin >> N >> K >> M) {
        memset(dp, -1, sizeof(dp));
        cout << solve(1, 1, 1) << "\n";
    }    
    return 0;
}
