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

const int MAXR = 30;
const int MAXC = 30;
int R, C, X, Y;
char land;
char world[MAXR][MAXC];
bool visited[MAXR][MAXC];

int distR[4] = {1, 0, -1, 0};
int distC[4] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return !(r < 0 || c < 0 || r >= R || c >= C);
}

int bfs(int r, int c) {
    queue<pair<int, int> > qq;
    qq.push(make_pair(r, c));
    visited[r][c] = true;

    int res = 0;
    while(!qq.empty()) {
        pair<int, int> el = qq.front();
        qq.pop();
        int curR = el.first;
        int curC = el.second;
        ++res;

        for(int i=0;i<4;++i) {
            int nextR = curR+distR[i];
            int nextC = (curC+distC[i]+C)%C; // (x, C-1) have an edge with (x, 0)
            if(isIn(nextR, nextC) && !visited[nextR][nextC] && world[nextR][nextC] == land) {
                qq.push(make_pair(nextR, nextC));
                visited[nextR][nextC] = true;
            }
        }
    }
    return res;
}

int main() {
    while(scanf("%d %d", &R, &C) == 2) {
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                scanf(" %c", &world[i][j]);
        scanf("%d %d", &X, &Y);
        land = world[X][Y];

        memset(visited, false, sizeof(visited));
        int ans = 0;
        bfs(X, Y);// remove captain continent
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                if(world[i][j] == land && !visited[i][j])
                    ans = max(ans, bfs(i, j));
        printf("%d\n", ans);

    }
    return 0;
}
