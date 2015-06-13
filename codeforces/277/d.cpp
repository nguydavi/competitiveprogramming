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
const int MAXN = 2010;
int D, N;
int arr[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int dp[MAXN];

/**
 * Every valid set can be uniquely determined by the smallest node in it.(If
 * there are more than 1 node has the smallest value, we choose the one who has
 * the smallest id). So let's choose a node to be our special node, and starts
 * to dfs under the limit that our special node has the smallest val and
 * smallest id. We get a sub-tree of the original one. And considered sub-tree,
 * You can use dp to count how many way you can choose a set which contains the
 * root (out special node)from the sub-tree.
 *
 * It's a classical dp problem on trees. dp[node] means the ways to choose a set
 * which contains the root and the others node come from the sub-tree of it. And
 * you want to calculate dp[x] for the the node x, you just go through his son,
 * and we can either not choose the part from this son's sub-tree or just take
 * it, which has dp[son] ways. So in total (1 + dp[son]) ways. Multiply the sons
 * choices up. And we get the ways to choose a set from the sub-tree of x which
 * contains the node x. As we can let every node in the tree to be our
 * root(spacial node), we can get the answer for the question.
 */
void solve(int cur, int root) {
    if(visited[cur])
        return;
    if(arr[cur] < arr[root] || arr[cur]-arr[root] > D)
        return;
    if(arr[cur] == arr[root] && cur < root) // avoid duplicate counting
        return;
    
    dp[cur] = 1;
    visited[cur] = true;
    for(int i=0;i<adj[cur].size();++i) {
        int v = adj[cur][i];
        if(!visited[v]) {
            solve(v, root);
            dp[cur] = (1LL * dp[cur] * (dp[v] + 1))%MOD;
        }
    }
}

int main() {
    scanf("%d %d", &D, &N); 
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    memset(adj, false, sizeof(adj));
    for(int i=0;i<N-1;++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int ans = 0;
    for(int i=0;i<N;++i) {
        memset(visited, false, sizeof(visited));
        memset(dp, 0, sizeof(dp));

        solve(i, i);

        ans += dp[i];
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}
