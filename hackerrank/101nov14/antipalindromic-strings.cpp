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
const ll MOD = (ll)1e9+7;
ll N, M;

ll powMod(ll base, ll exp) {
    if(exp == 0)
        return 1;
    else {
        ll res = powMod(base, exp/2);
        res *= res;
        res %= MOD;
        if(exp%2==1) {
            res *= base;
            res %= MOD;
        }
        return res%MOD;
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%lld %lld", &N, &M);

        ll ans;
        if(N == 1)
            ans = M;
        else if(N == 2)
            ans = M*(M-1);
        else
            ans = ((M*(M-1))%MOD)*powMod(M-2, N-2);
        ans %= MOD;
        printf("%d\n", (int)ans);
    }
    return 0;
}
