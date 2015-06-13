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
typedef long long ll;
const int MAXN = 1e5+10;
int N, M;
vector<vector<pii> > adjList;
bool vis[MAXN];

bool findPath(int cur, int dest, vector<int>& path) {
    vis[cur] = true;
    if(cur == dest)
        return true;

    for(pii nxtP : adjList[cur]) {
        int nxt = nxtP.first;
        int nxtD = nxtP.second;

        path.push_back(nxtD);
        if(!vis[nxt] && findPath(nxt, dest, path))
            return true;
        path.pop_back();
    }
    return false;
}

ll solve(int a, int b) {
    memset(vis, false, sizeof(vis));
    vector<int> path;
    findPath(a, b, path);

    ll res = 0;
    for(int x : path)
        res += x;
    return res;
}

int main() {
    while(scanf("%d", &N) == 1 && N) {
        adjList.assign(N, vector<pii>());
        for(int i=1;i<=N-1;++i) {
            int v, d;
            scanf("%d %d", &v, &d);
            adjList[i].push_back({v, d});
            adjList[v].push_back({i, d});
        }

        scanf("%d", &M);
        for(int i=0;i<M;++i) {
            int a, b;
            scanf("%d %d", &a, &b);

            if(i)
                printf(" ");
            printf("%lld", solve(a, b));
        }
        printf("\n");
    }
    return 0;
}
