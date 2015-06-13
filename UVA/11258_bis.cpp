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
typedef pair<int, ll> pil;
const int MAXN = 210;
const int MAX_INT = (1LL<<31) - 1;
int N;
string a;
map<pil, ll> dp;

ll solve(int index, ll cur) {
    if(index == N)
        return cur;
    if(dp.find(pil(index, cur)) != dp.end())
        return dp[pil(index, cur)];

    int dig = a[index]-'0';
    ll res = cur+solve(index+1, dig);

    if(10*cur+dig <= MAX_INT) {
        int newCur = 10*cur + dig;
        res = max(res, solve(index+1, newCur));
    }

    dp[pil(index, cur)] = res;
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        dp.clear();
        cin >> a;
        N = a.size();
        cout << solve(0, 0LL) << "\n";
    }
    return 0;
}
