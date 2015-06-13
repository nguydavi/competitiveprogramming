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
const int MAXK = 110;
const int MOD = 1000000;
int N, K;
int dp[MAXN][MAXK];

int solve(int sum, int k) {
    if(sum == N && k == K)
        return 1;
    if(sum > N || k > K)
        return 0;
    if(dp[sum][k] != -1)
        return dp[sum][k];

    int ans = 0;
    for(int i=0;i<=N;++i)
        ans += solve(sum+i, k+1)%MOD, ans%=MOD;
    return dp[sum][k] = ans;
}

int main() {
    while(cin >> N >> K && N && K) {
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << "\n";
    }    
    return 0;
}
