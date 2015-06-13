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

const int MAXN = 100;
const int INF = (int)1e9;
int N;
string a;
int dp[MAXN][MAXN];

int solve(int start, int end) {
    if(start == N)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];

    int res = end-start;
    for(int i=1;i<end-start;++i) {
        int j = i;
        while(j < end-start && a[start+(j%i)] == a[start+j])
            ++j;
        int cnt = j/i;
        res = min(res, solve(start, start+i) + solve(start+cnt*i, end));
    }

    dp[start][end] = res;
    return res;
}

int main() {
    while(cin >> a && a != "*") {
        memset(dp, -1, sizeof(dp));
        N = a.size();
        cout << solve(0, N) << "\n";
    }
    return 0;
}
