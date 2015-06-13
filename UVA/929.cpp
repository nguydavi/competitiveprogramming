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
const int MAXR = 1010;
const int MAXC = 1010;
const int INF = (int)1e9;
int R, C;
int mat[MAXR][MAXC];
int dist[MAXR][MAXC];

int dR[] = {1, 0, -1, 0};
int dC[] = {0, 1, 0, -1};

bool isIn(pii u) {
    return u.first >= 0 && u.first < R && u.second >= 0 && u.second < C;
}

int solve() {
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            dist[i][j] = INF;
    dist[0][0] = mat[0][0];
    priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
    pq.push(make_pair(mat[0][0], make_pair(0, 0)));

    while(!pq.empty()) {
        pair<int, pii> cur = pq.top();
        pq.pop();
        pii v = cur.second;
        int d = cur.first;
        if(d <= dist[v.first][v.second])
            dist[v.first][v.second] = d;
            for(int i=0;i<4;++i) {
                pii nxt = make_pair(v.first + dR[i], v.second + dC[i]);
                if(isIn(nxt) && dist[v.first][v.second] + mat[nxt.first][nxt.second] < dist[nxt.first][nxt.second]) {
                    dist[nxt.first][nxt.second] = dist[v.first][v.second] + mat[nxt.first][nxt.second];
                    pq.push(make_pair(dist[nxt.first][nxt.second], nxt));
                }
            }
    }
    return dist[R-1][C-1];
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &R, &C);
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j)
                scanf("%d", &mat[i][j]);
        printf("%d\n", solve());
    }
    return 0;
}
