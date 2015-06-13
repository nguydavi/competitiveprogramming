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
bool isPal[MAXN][MAXN];
int N, M;

int dp[MAXN][MAXN];

int solve(int start, int end) {
    if(start < 0 || end >= N || start > end)
        return 0;
    if(dp[start][end] != -1)
        return dp[start][end];

    int res = solve(start, end-1) + solve(start+1, end) 
            - solve(start+1, end-1) + isPal[start][end];
    dp[start][end] = res;
    return res;
}

int main() {
    string s;
    cin >> s >> M;
    N = s.size();

    memset(isPal, false, sizeof(isPal));
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;++i) {
        isPal[i][i] = true;
        if(i+1<N)
            isPal[i][i+1] = (s[i] == s[i+1]);
    }
    for(int len=3; len<N;++len)
        for(int i=0;i+len-1<N;++i)
            isPal[i][i+len-1] = isPal[i+1][i+len-2] && (s[i] == s[i+len-1]);

    while(M--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a-1, b-1) << "\n";
    }
    return 0;
}
