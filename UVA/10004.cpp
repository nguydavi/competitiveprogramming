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

bool bfs() {
    memset(color, -1, sizeof(color));
    queue<int> qq;
    qq.push(0);
    color[0] = BLACK;

    while(!qq.empty()) {
        int cur = qq.front();
        qq.pop();

        for(int i=0;i<N;++i)
            if(adj[cur][i]) {
                if(color[i] != -1 && color[i] != (color[cur]^1))
                    return false;

                if(color[i] == -1) {
                    qq.push(i);
                    color[i] = color[cur]^1;
                }
            }
    }
    return true;
}

int main() {
    while(scanf("%d", &N) == 1 && N) {
        memset(adj, false, sizeof(adj));
        scanf("%d", &M);
        for(int i=0;i<M;++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][b] = adj[b][a] = true;
        }

        bool ans = bfs();
        if(ans)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");

    } 
    return 0;
}
