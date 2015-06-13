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

const int MOD = (int)1e9+7;
const int MAXH = 1000;
const int MAXR = 300000;
int R,G;
int dp[MAXR];

int solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    int hh = 1;
    while((hh+1)*(hh+2)/2 <= R+G)
        ++hh;

    for(int h=1;h<=hh;++h)
        for(int r=R;r>=h;--r)
            dp[r] = (dp[r-h] + dp[r])%MOD;

    int ans = 0;
    for(int r=0;r<=R;++r)
        if(hh*(hh+1)/2 - r <= G)
            ans += dp[r], ans %=MOD;
    return ans;
}

int main() {
    cin >> R >> G;
    cout << solve() << "\n";
    return 0;
}
