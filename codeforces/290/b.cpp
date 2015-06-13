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

const int MAXN = 100;
int N, M;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dirR[] = {0, 1, 0, -1};
int dirC[] = {1, 0, -1, 0};

int dp[MAXN][MAXN];

bool dfs(int r, int c, int prevR, int prevC, char color) {
    if(r < 0 || r >= N || c < 0 || c >= M || mat[r][c] != color)
        return false;
    if(vis[r][c])
        return true;
    if(dp[r][c] != -1)
        return dp[r][c];

    vis[r][c] = true;
    bool res = false;
    for(int i=0;i<4;++i) {
        int nxtR = r+dirR[i];
        int nxtC = c+dirC[i];
        if(nxtR != prevR || nxtC != prevC)
            res = res | dfs(nxtR, nxtC, r, c, color);
    }

    dp[r][c] = res;
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            scanf(" %c", &mat[i][j]);

    for(int i=0;i<N-1;++i)
        for(int j=0;j<M-1;++j) {
            memset(vis, false, sizeof(vis));
            memset(dp, -1, sizeof(dp));
            if(dfs(i, j, -1, -1, mat[i][j])) {
                printf("Yes\n");
                return 0;
            }
        }
    printf("No\n");
    return 0;
}
