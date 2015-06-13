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
bool isPal[MAXN][MAXN];
int N, M;

int dp[MAXN][MAXN];

int main() {
    string s;
    cin >> s >> M;
    N = s.size();

    memset(isPal, false, sizeof(isPal));
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<N;++i) {
        isPal[i][i] = true;
        if(i+1<N)
            isPal[i][i+1] = (s[i] == s[i+1]);
    }
    for(int i=0;i<N;++i) {
        dp[i][i] = 1;
        if(i+1<N)
            dp[i][i+1] = isPal[i][i] + isPal[i+1][i+1] + isPal[i][i+1];
    }

    for(int len=3; len<=N;++len)
        for(int i=0;i+len-1<N;++i) {
            isPal[i][i+len-1] = isPal[i+1][i+len-2] && (s[i] == s[i+len-1]);
            dp[i][i+len-1] = dp[i][i+len-2] + dp[i+1][i+len-1] - dp[i+1][i+len-2] + isPal[i][i+len-1];
        }

    while(M--) {
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-1] << "\n";
    }
    return 0;
}
