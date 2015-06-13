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

const int MAXN = 200010;
const int INF = (int)1e9;
int N;
vector<int> adjList[MAXN];
map<int, int> mm;//map student id-> node id
int arr[MAXN];

int dp[MAXN];
bool vis[MAXN];
int ans[MAXN];

int dfs(int n) {
    if(n == mm[INF])
        return 0;
    if(dp[n] != -1)
        return dp[n];

    vis[n] = true;
    if(adjList[n].empty())
        return 1;
    return dp[n] = 1+dfs(adjList[n][0]);
}

void dfs2(int index, int n) {
    ans[index] = arr[n];
    if(adjList[n].empty())
        return;
    dfs2(index+2, adjList[n][0]);
}

int main() {
    scanf("%d", &N);
    int index = 1;
    mm[0] = 0;
    mm[INF] = N+1;
    for(int i=0;i<N;++i) {
        int u,v;
        scanf("%d %d", &u, &v);
        if(v == 0)
            v = INF;

        if(mm.find(u) == mm.end()) {
            mm[u] = index, arr[index] = u;
            ++index;
        }
        if(mm.find(v) == mm.end()) {
            mm[v] = index, arr[index] = v;
            ++index;
        }

        adjList[mm[u]].push_back(mm[v]);
    }

    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    int start = -1;
    int maxLen = 0;
    dfs(0);
    for(int i=1;i<=N;++i)
        if(!vis[i]) {
            int leng = dfs(i);
            if(leng > maxLen) {
                maxLen = leng;
                start = i;
            }
        }
    dfs2(0, 0);
    dfs2(1, start);
    for(int i=1;i<=N;++i) {
        if(i > 1)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
