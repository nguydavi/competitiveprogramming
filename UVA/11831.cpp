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

const char CELL = '.';
const char STICKER = '*';
const char PILLAR = '#';
const int MAXN = 110;
const int MAXM = 110;
int N, M, S;
int curRow, curCol;
int dir;
char mat[MAXN][MAXM];
int ans;

pair<int ,int> nextCell() {
    if(dir == 0)
        return make_pair(curRow-1, curCol);
    if(dir == 90)
        return make_pair(curRow, curCol+1);
    if(dir == 180)
        return make_pair(curRow+1, curCol);
    if(dir == 270)
        return make_pair(curRow, curCol-1);
}

void move(char a) {
    if(a == 'F') {
        pair<int, int> next = nextCell();
        if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M || mat[next.first][next.second] == PILLAR)
            return;
        curRow = next.first;
        curCol = next.second;
        if(mat[curRow][curCol] == STICKER) {
            ++ans;
            mat[curRow][curCol] = CELL;
        }

    } else if(a == 'D')
        dir += 90;
    else if(a =='E')
        dir -= 90;
    dir = (dir + 360)%360;
}

int main() {
    while(scanf("%d %d %d", &N, &M, &S) == 3 && N && M && S) {
        ans = 0;
        for(int i=0;i<N;++i)
            for(int j=0;j<M;++j) {
                scanf(" %c", &mat[i][j]);
                if(mat[i][j] != CELL && mat[i][j] != STICKER && mat[i][j] != PILLAR) {
                    curRow = i;
                    curCol = j;
                    if(mat[i][j] == 'N')
                        dir = 0;
                    else if(mat[i][j] == 'S')
                        dir = 180;
                    else if(mat[i][j] == 'L')
                        dir = 90;
                    else
                        dir = 270;
                }
            }
       
        for(int i=0;i<S;++i) {
            char m;
            scanf(" %c", &m);
            move(m);
        }
        printf("%d\n", ans);

    }
    return 0;
}
