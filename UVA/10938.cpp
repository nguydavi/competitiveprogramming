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
int N, M;
vector<vector<int> > adjList;
bool vis[MAXN];

bool findPath(int cur, int dest, vector<int>& path) {
    vis[cur] = true;
    path.push_back(cur);
    if(cur == dest)
        return true;

    for(int nxt : adjList[cur])
        if(!vis[nxt] && findPath(nxt, dest, path))
            return true;

    path.pop_back();
    return false;
}

vector<int> solve(int a, int b) {
    memset(vis, false, sizeof(vis));
    vector<int> path;
    findPath(a, b, path);

    vector<int> res;
    if(path.size()%2 == 0) {
        res.push_back(path[path.size()/2]);
        res.push_back(path[path.size()/2-1]);
        sort(res.begin(), res.end());
    } else
        res.push_back(path[path.size()/2]);

    return res;
}

int main() {
    while(scanf("%d", &N) == 1 && N) {
        adjList.assign(N, vector<int>());
        for(int i=0;i<N-1;++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        scanf("%d", &M);
        while(M--) {
            int a, b;
            scanf("%d %d", &a, &b);
            --a, --b;

            vector<int> ans = solve(a, b);
            if(ans.size() == 1)
                printf("The fleas meet at %d.\n", ans[0]+1);
            else
                printf("The fleas jump forever between %d and %d.\n", ans[0]+1, ans[1]+1);
        }
    }
    return 0;
}
