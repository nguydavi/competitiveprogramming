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

const int MAXN = 400;
int N;
int arr[MAXN];
int mat[MAXN][MAXN];
bool vis[MAXN];

/**
 * Find connected components and sort each of them separately.
 * Each connected components can be sorted on their own because any swap is
 * possible within them (just swap until wanted position)
 *
 * Note: matrix is symmetric
 */
void dfs(int cur, vector<int>& vv, vector<int>& tt) {
    vv.push_back(arr[cur]);
    tt.push_back(cur);
    vis[cur] = true;

    for(int i=0;i<N;++i)
        if(!vis[i] && mat[cur][i])
            dfs(i, vv, tt);
}

vector<int> solve() {
    vector<int> res(N, -1);
    memset(vis, false, sizeof(vis));
    
    for(int i=0;i<N;++i) {
        if(!vis[i]) {
            vector<int> vv, tt;
            dfs(i, vv, tt);
            sort(vv.begin(), vv.end());
            sort(tt.begin(), tt.end());
            for(int j=0;j<vv.size();++j)
                res[tt[j]] = vv[j];
        }
    }

    return res;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d", &arr[i]);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j) {
            char a;
            scanf(" %c", &a);
            mat[i][j] = a-'0';
        }

    vector<int> ans = solve();
    for(int i=0;i<N;++i) {
        if(i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
        

    return 0;
}
