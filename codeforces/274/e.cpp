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

const int MAXK = 5010;
const int MAXN = 5010;
const int MOD = (int)1e9+7;
int N,A,B,K;
int dp[MAXK][MAXN];

int main() {
    cin >> N >> A >> B >> K; 
    memset(dp, 0, sizeof(dp));
    dp[0][A] = 1;

    // Good logic but O(kn^2) -> TLE, can replace one of the loop with partial
    // sums -> O(kn)
    for(int k=1;k<=K;++k)
        for(int f=1;f<=N;++f)
            for(int x=1;x<=N;++x)
                if(x!=f && abs(x-f) < abs(x-B))
                    dp[k][f] = dp[k][f]%MOD + dp[k-1][x]%MOD;
    
    int ans = 0;
    for(int f=1;f<=N;++f)
        ans = ans%MOD + dp[K][f]%MOD;
    cout << ans << "\n";

    return 0;
}
