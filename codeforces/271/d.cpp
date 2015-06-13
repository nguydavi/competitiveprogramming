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

#define MAXLEN 100010
#define MOD 1000000007
int K, T;
int dp[MAXLEN], psum[MAXLEN];

void solve() {
    for(int i=0;i<K;++i)
        dp[i] = 1;
    dp[K] = 2;

    for(int i=K+1;i<MAXLEN; ++i)
        dp[i] = (dp[i-1]%MOD + dp[i-K]%MOD)%MOD;

    int sum = 0;
    for(int i=0;i<MAXLEN;++i)
        sum += dp[i], sum%=MOD, psum[i] = sum;
}

int main() {
    cin >> T >> K;
    solve();
    while(T--) {
        int a, b;
        cin >> a >> b;
        cout << (psum[b]-psum[a-1]+MOD)%MOD << "\n";
    } 
    return 0;
}
