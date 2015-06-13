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

const int MAXCOINS = 5;
const int MAXN = 30100;
int N, M;
int coins[MAXCOINS] = {1, 5, 10, 25, 50};
ll dp[MAXN];

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0;i<MAXCOINS;++i)
        for(int j=coins[i];j<MAXN;++j)
            dp[j] += dp[j-coins[i]];
}

int main() {
    solve();
    while(cin >> N) {
        if(dp[N] == 1)
            cout << "There is only " << dp[N] << " way to produce " << N << " cents change.\n";
        else
            cout << "There are " << dp[N] << " ways to produce " << N << " cents change.\n";
    }    
    return 0;
}
