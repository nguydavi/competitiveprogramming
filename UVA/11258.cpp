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
const int MAXN = 210;
const int MAX_INT = (1LL<<31) - 1;
int N;
string a;
ll dp[MAXN];

ll solve(int index, ll cur) {
    if(index == N)
        return cur;

    int dig = a[index]-'0';
    ll res;
    if(dp[index] != -1)
        res = cur+dp[index];
    else {
        ll t = solve(index+1, dig);
        dp[index] = t;
        res = cur+t;
    }

    if(10*cur+dig <= MAX_INT) {
        cur = 10*cur + dig;
        res = max(res, solve(index+1, cur));
    }

    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        memset(dp, -1, sizeof(dp));
        cin >> a;
        N = a.size();
        cout << solve(0, 0LL) << "\n";
    }
    return 0;
}
