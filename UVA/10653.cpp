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

const int MAXR = 1010;
const int MAXC = 1010;
const int INF = (int)1e9;
int R, C;
bool mat[MAXR][MAXC];
int dist[MAXR][MAXC];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool isIn(const pair<int, int>& v) {
    if(v.first >= 0 && v.first < R && v.second >= 0 && v.second < C)
        return true;
    return false;
}

int solve(int startR, int startC, int endR, int endC) {
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            dist[i][j] = INF;

    queue<pair<int, int> > qq;
    qq.push(make_pair(startR, startC));
    dist[startR][startC] = 0;

    while(!qq.empty()) {
        pair<int, int> u = qq.front();
        qq.pop();
        for(int i=0;i<4;++i) {
            pair<int, int> v = make_pair(u.first+dr[i], u.second+dc[i]);
            if(isIn(v) && !mat[v.first][v.second] && dist[v.first][v.second] == INF) {
                dist[v.first][v.second] = dist[u.first][u.second]+1;
                qq.push(v);
            }
        }
    }
    return dist[endR][endC];
}

int main() {
    while(scanf("%d %d", &R, &C) && (R || C)) {
        memset(mat, false, sizeof(mat));
        int M;
        scanf("%d", &M);
        while(M--) {
            int row, nb;
            scanf("%d %d", &row, &nb);
            while(nb--) {
                int c;
                scanf("%d", &c);
                mat[row][c] = true;
            }
        }

        int startR, startC;
        scanf("%d %d", &startR, &startC);
        int endR, endC;
        scanf("%d %d", &endR, &endC);

        printf("%d\n", solve(startR, startC, endR, endC));
    }
    return 0;
}
