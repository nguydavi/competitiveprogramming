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

#define MAXITEM 200
#define MAXMONEY 20000
int M, N;
pair<int, int> arr[MAXITEM];
int dp[MAXITEM][MAXMONEY];

int solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=N;++i) {
        dp[i][0] = 0;
        for(int j=1;j<=M+300;++j) {
            if(j>=arr[i-1].first && dp[i-1][j-arr[i-1].first] != -1)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i-1].first] + arr[i-1].second);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int ans = 0;
    for(int j=0;j<=M;++j)
        ans = max(ans, dp[N][j]);
    for(int j=2001;j<=M+200;++j)
        ans = max(ans, dp[N][j]);
    return ans;
}

int main() {
    while(cin >> M >> N) {
        for(int i=0;i<N;++i) {
            int p, f;
            cin >> p >> f;
            arr[i] = make_pair(p, f);
        }
        cout << solve() << "\n";
    } 
    return 0;
}
