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
const char CELL = '.';
const char HIT = '@';
const char SHIP = 'x';
int N;
char world[MAXN][MAXN];
bool vis[MAXN][MAXN];

int distR[4] = {1, 0, -1, 0};
int distC[4] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return !(r < 0 || c < 0 || r >= N || c >= N);
}

bool bfs(int r, int c) {
    queue<pair<int, int> > qq;
    qq.push(make_pair(r, c));
    vis[r][c] = true;

    bool alive = (world[r][c] == SHIP);
    while(!qq.empty()) {
        pair<int, int> el = qq.front();
        qq.pop();
        int curR = el.first;
        int curC = el.second;
        
        for(int i=0;i<4;++i) {
            int nextR = curR + distR[i];
            int nextC = curC + distC[i];
            if(!vis[nextR][nextC] && isIn(nextR, nextC) && world[nextR][nextC] != CELL) {
                qq.push(make_pair(nextR, nextC));
                vis[nextR][nextC] = true;
                alive |= (world[nextR][nextC] == SHIP);
            }
        }
    }
    return alive;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                scanf(" %c", &world[i][j]);
        memset(vis, false, sizeof(vis));
        
        int ans = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(!vis[i][j] && world[i][j] != CELL) {
                    bool alive = bfs(i, j);
                    if(alive)
                        ++ans;
                }
        printf("Case %d: %d\n", ii, ans);
    }    
    return 0;
}
