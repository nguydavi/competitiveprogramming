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

const int MAXN = 5010;
const int BASE1 = 31;
const int BASE2 = 313;
const int MOD = 1e9+7;
int N, M;

int hh1[MAXN], hh2[MAXN], rhh1[MAXN], rhh2[MAXN];
int pw1[MAXN], pw2[MAXN];
int dp[MAXN][MAXN];

void myhash(const string& s, int base, int hh[]) {
    hh[0] = 0;
    for(int i=0;i<N;++i) {
        char c = s[i];
        hh[i] = (1LL*hh[i-1]*base + (c-'a'+1))%MOD;
    }
}

int gethash(int start, int end, int hh[], int pw[]) {
    int res = hh[end];
    if(start > 0)
        res -= (1LL*hh[start-1]*pw[end-start+1])%MOD;
    return (res+MOD)%MOD;
}

bool isPal(int start, int end) {
    return gethash(start, end, hh1, pw1) == gethash(N-1-end, N-1-start, rhh1, pw1)
        && gethash(start, end, hh2, pw2) == gethash(N-1-end, N-1-start, rhh2, pw2);

}

int solve(int start, int end) {
    if(start < 0 || end >= N || start > end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];

    int res = solve(start, end-1) + solve(start+1, end) 
            - solve(start+1, end-1) + isPal(start, end);
    dp[start][end] = res;
    return res;
}

int main() {
    string s;
    cin >> s >> M;
    N = s.size();

    pw1[0] = pw2[0] = 1;
    for(int i=1;i<=N;++i) {
        pw1[i] = (1LL*pw1[i-1]*BASE1)%MOD;
        pw2[i] = (1LL*pw2[i-1]*BASE2)%MOD;
    }
    myhash(s, BASE1, hh1), myhash(s, BASE2, hh2);
    string rs(s);
    reverse(rs.begin(), rs.end());
    myhash(rs, BASE1, rhh1), myhash(rs, BASE2, rhh2);

    memset(dp, -1, sizeof(dp));
    while(M--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a-1, b-1) << "\n";
    }
    return 0;
}
