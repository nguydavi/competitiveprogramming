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
const int MAXM = 110;
const int MAXN = 110;
int M, N;
int SR, SC, GR, GC;
vector<string> arr(MAXM);

int dirR[4] = {-1, 0, 1, 0};
int dirC[4] = {0, 1, 0, -1};
char lasers[4] = {'<', '^', '>', 'v'};
bool vis[MAXM][MAXM][4];
map<char, int> mm;

bool canGo(int row, int col) {
    return 0 <= row && row < M && 0 <= col && col < N && arr[row][col] == '.';
}

bool checkLasers(int row, int col, int dist) {
    int curRow = row;
    while(curRow  >= 0) {
        if(arr[curRow][col] != '.') {
           if(arr[curRow][col] != '#' && lasers[(mm[arr[curRow][col]]+dist)%4] == 'v')
               return false;
           break;
        }
        --curRow;
    }
    curRow = row;
    while(curRow < M) {
        if(arr[curRow][col] != '.') {
            if(arr[curRow][col] != '#' && lasers[(mm[arr[curRow][col]]+dist)%4] == '^')
                return false;
            break;
        }
        ++curRow;
    }
    int curCol = col;
    while(curCol >= 0) {
        if(arr[row][curCol] != '.') {
            if(arr[row][curCol] != '#' && lasers[(mm[arr[row][curCol]]+dist)%4] == '>')
                return false;
            break;
        }
        --curCol;
    }
    curCol = col;
    while(curCol < N) {
        if(arr[row][curCol] != '.') {
            if(arr[row][curCol] != '#' && lasers[(mm[arr[row][curCol]]+dist)%4] == '<')
                return false;
            break;
        }
        ++curCol;
    }
    return true;
}

int solve() {
    memset(vis, false, sizeof(vis));
    queue<pair<pii, int> > q;
    q.push(make_pair(pii(SR,SC), 0));
    vis[SR][SC][0] = true;

    while(!q.empty()) {
        pair<pii, int> cur = q.front();
        q.pop();
        int curR = cur.first.first;
        int curC = cur.first.second;
        int curDist = cur.second;

        for(int i=0;i<4;++i) {
            int nxtR = curR + dirR[i];
            int nxtC = curC + dirC[i];
            int nxtDist = curDist+1;
            if(canGo(nxtR, nxtC) && checkLasers(nxtR, nxtC, nxtDist) && !vis[nxtR][nxtC][nxtDist%4]) {
                if(nxtR == GR && nxtC == GC)
                    return nxtDist;
                vis[nxtR][nxtC][nxtDist%4] = true;
                q.push(make_pair(pii(nxtR, nxtC), nxtDist));
            }
        }
    }
    return -1;
}

int main() {
    mm['<'] = 0;
    mm['^'] = 1;
    mm['>'] = 2;
    mm['v'] = 3;

    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        cin >> M >> N;
        if(!M)
            break;
        for(int i=0;i<M;++i) {
            cin >> arr[i];
            for(int j=0;j<arr[i].size();++j)
                if(arr[i][j] == 'S')
                    SR = i, SC = j;
                else if(arr[i][j] == 'G')
                    GR = i, GC = j;
        }
        arr[SR][SC] = arr[GR][GC] = '.';

        int ans = solve();
        cout << "Case #" << ii << ": ";
        if(ans == -1)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
