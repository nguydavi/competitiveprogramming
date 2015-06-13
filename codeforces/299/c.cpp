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
ll A, B, N;

ll height(int i) {
    return A+(i-1)*B;
}

ll sumN(int n) {
    return (ll)n*(n+1)/2;
}

ll sumLX(ll l, ll x) {
    return (ll)A*(1+x-l) + (ll)(sumN(x-1)-sumN(l-2))*B;
}

ll solve(ll L, ll T, ll M) {
    int left = L;
    int right = 2e6;
    while(left < right) {
        int mid = (left+right)/2;
        if(sumLX(L, mid) <= T*M)
            left = mid+1;
        else
            right = mid;
    }
    return left-1;
}

int main() {
    cin >> A >> B >> N;
    while(N--) {
        ll L, T, M;
        cin >> L >> T >> M;

        if(T < height(L)) {
            cout << -1 << "\n";
            continue;
        }

        ll ans = min((T-A)/B+1, solve(L, T, M));
        cout << ans << "\n";
    }
    return 0;
}
