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

const int MAXN = 30;
const int MAXG = 1010;
int GP, GC, GF;
int N;
int arr[MAXN][3];

struct state {
    int index;
    int p, c, f;

    bool operator==(const state& st) const {
        return index == st.index && p == st.p && c == st.c && f == st.f;
    }

    bool operator<(const state& st) const {
        vector<int> v1 = {index, p, c, f};
        vector<int> v2 = {st.index, st.p, st.c, st.f};
        return v1 < v2;
    }
};

map<state, bool> dp;

/**
 * DP is correct but too many states possible, doesn't use memoization here
 */
bool solve(int index, int p, int c, int f) {
    if(p == 0 && c == 0 && f == 0)
        return true;
    if(index < 0 || p <= 0 || c <= 0 || f <= 0)
        return false;
    if(dp.find({index, p, c, f}) != dp.end())
        return dp[{index, p, c, f}];

    bool r1 = solve(index-1, p, c, f);
    bool r2 = solve(index-1, p-arr[index][0], c-arr[index][1], f-arr[index][2]);
    dp[{index, p, c, f}] = r1 || r2;
    return r1 || r2;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d", &GP, &GC, &GF);
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

        dp.clear();
        bool ans = solve(N-1, GP, GC, GF);
        if(ans)
            printf("Case #%d: yes\n", ii);
        else
            printf("Case #%d: no\n", ii);
    }
    return 0;
}
