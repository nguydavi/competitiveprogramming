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

int poss[] = {192, 442, 692, 942};

ll solve(ll k) {
    ll res = 1000LL * (k/4);
    res += poss[k%4];
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        ll K;
        scanf("%lld", &K);
        printf("%lld\n", solve(K-1));
    }

    return 0;
}
