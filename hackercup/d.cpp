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

typedef pair<int, int> pii;
const int INF = 1e9;
const int MAXN = 2e5+10;
const int MAXVAL = 25;
int N;
int arr[MAXN];
vector<vector<int > > adjList;
int dp[MAXN][MAXVAL];

int dfs(int cur, int prev, int val) {
    if(dp[cur][val] != -1)
        return dp[cur][val];

    int res = val;
    for(int nxt : adjList[cur])
        if(nxt != prev) {
            int nxtRes = INF;
            for(int j=1;j<MAXVAL;++j)
                if(j!=val)
                    nxtRes = min(nxtRes, dfs(nxt, cur, j));
            res += nxtRes;
        }

    dp[cur][val] = res;
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d", &N);
        adjList.assign(N, vector<int>());
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
            if(i) {
                --arr[i];
                adjList[i].push_back(arr[i]);
                adjList[arr[i]].push_back(i);
            }
        }

        memset(dp, -1, sizeof(dp));
        int ans = INF;
        for(int i=1;i<MAXVAL;++i)
            ans = min(ans, dfs(0, -1, i));

        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}
