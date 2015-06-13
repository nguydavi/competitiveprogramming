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
const int MOD = 1e9+7;
const int MAXN = 2010;
int maxA, maxB;

ll dpfree[MAXN][MAXN];
ll dpful[MAXN][MAXN];

ll stressfree(int A, int B) {
    if(A == 1 || B == 0)
        return 1;
    if(dpfree[A][B] != -1)
        return dpfree[A][B];

    ll res = stressfree(A, B-1);
    if(A-1 > B)
        res += stressfree(A-1, B);

    res %= MOD;
    dpfree[A][B] = res;
    return res;
}

ll stressful(int A, int B) {
    if(A == 0 || B == 0)
        return 1;
    if(dpful[A][B] != -1)
        return dpful[A][B];

    ll res = stressful(A-1, B);
    if(B-1 >= A)
        res += stressful(A, B-1);

    res %= MOD;
    dpful[A][B] = res;
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d-%d", &maxA, &maxB);

        memset(dpfree, -1, sizeof(dpfree));
        memset(dpful, -1, sizeof(dpful));
        ll ans1 = stressfree(maxA, maxB);
        ll ans2 = stressful(maxB, maxB);
        printf("Case #%d: %lld %lld\n", ii, ans1, ans2);
    }
    return 0;
}
