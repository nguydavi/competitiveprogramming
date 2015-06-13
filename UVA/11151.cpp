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

const int MAXN = 2000;
int N;
string a, b;
int dp[MAXN][MAXN];

int solve() {
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j) {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j-1];

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    return dp[N][N];
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--) {
        getline(cin, a);
        N = a.size();
        b = string(a.rbegin(), a.rend());
        cout << solve() << "\n";
    }
    return 0;
}
