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

const int MAXN = 110;
int N, M;
bool adj[MAXN][MAXN];
deque<int> ans;
bool vis[MAXN];

void dfs(int id) {
    vis[id] = true;
    for(int i=0;i<N;++i)
        if(adj[id][i] && !vis[i])
            dfs(i);
    ans.push_front(id+1);
}

int main() {
    while(scanf("%d %d", &N, &M) == 2 && (N || M)) {
        memset(adj, false, sizeof(adj));
        memset(vis, false, sizeof(vis));
        for(int i=0;i<M;++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a-1][b-1] = true;
        }

        ans.clear();
        for(int i=0;i<N;++i)
            if(!vis[i])
                dfs(i);

        printf("%d", ans[0]);
        for(int i=1;i<N;++i)
            printf(" %d", ans[i]);
        printf("\n");

    } 
    return 0;
}
