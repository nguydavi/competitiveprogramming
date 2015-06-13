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

const int MAXN = 210;
const int BLACK = 0;
const int WHITE = 1;
int N, M;
bool adj[MAXN][MAXN];
int color[MAXN];

int countBlack, totalColors;
bool bfs(int id) {
    queue<int> qq;
    qq.push(id);
    color[id] = BLACK;
    ++countBlack;

    while(!qq.empty()) {
        int cur = qq.front();
        qq.pop();
        ++totalColors;

        for(int i=0;i<N;++i)
            if(adj[cur][i]) {
                if(color[i] != -1 && color[i] != color[cur]^1)
                    return false;

                if(color[i] == -1) {
                    qq.push(i);
                    color[i] = color[cur]^1;
                    if(color[i] == BLACK)
                        ++countBlack;
                }
            }
    }
    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &M);
        memset(adj, false, sizeof(adj));
        for(int i=0;i<M;++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][b] = adj[b][a] = true;
        }

        memset(color, -1, sizeof(color));
        bool ans = false;
        int res = 0;
        for(int i=0;i<N;++i)
            if(color[i] == -1) {
                countBlack = totalColors = 0;
                ans |= bfs(i);
                res += countBlack == totalColors ?  countBlack : min(countBlack, totalColors-countBlack);
            }

        if(!ans)
            printf("-1\n");
        else
            printf("%d\n", res);
    }    
    return 0;
}
