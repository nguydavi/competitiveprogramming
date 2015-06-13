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
const int LEFT = 0;
const int RIGHT = 1;
ll H, N;
ll ans;

void solve(ll L, ll R, int lastMove) {
    if(L >= R)
        return;

    ll mid = (L+R)/2;
    ++ans;
    if(N <= mid) {
        if(lastMove == LEFT)
            ans += (R-mid) * 2 - 1;
        solve(L, mid, LEFT);
    } else {
        if(lastMove == RIGHT)
            ans += (mid-L+1) * 2 - 1;
        solve(mid+1, R, RIGHT);
    }
}

int main() {
    cin >> H >> N;
    --N;
    ans = 0;
    solve(0, (1LL<<H)-1, RIGHT);

    cout << ans << "\n";
    return 0;
}
