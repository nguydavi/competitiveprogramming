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
const int MAXM = 110;
int N, M, Q;
vector<int> mat[MAXN][MAXM];
bool vis[MAXN];

int dfs(int u, int v, int color) {
    if(u == v)
        return color;

    //cout << "DEBUG " << u << " " << v << " " << color << endl;
    vis[u] = true;
    int res = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<mat[u][i].size();++j)
            if(mat[u][i][j] == color && !vis[i]) {
                res = dfs(i, v, color);
                if(res != 0)
                    break;
            }
        if(res)
            break;
    }
    vis[u] = false;
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            mat[i][j] = vector<int>();

    for(int i=0;i<M;++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        mat[a][b].push_back(c);
        mat[b][a].push_back(c);
    }

    scanf("%d", &Q);
    while(Q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;

        int ans = 0;
        for(int j=1;j<=M;++j) {
            memset(vis, false, sizeof(vis));
            if(dfs(u, v, j))
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
