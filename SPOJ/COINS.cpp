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
map<int, ll> dp;

ll solve(int n) {
    if(n == 0)
        return 0;
    if(dp.find(n) != dp.end())
        return dp[n];

    ll res = max(1LL*n, solve(n/2)+solve(n/3)+solve(n/4));
    dp[n] = res;
    return res;
}

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        dp.clear();
        printf("%lld\n", solve(N));
    }
    return 0;
}
