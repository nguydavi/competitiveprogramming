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

const int MAXR = 110;
const int MAXC = 110;
int R, C, M, N, W;
int mat[MAXR][MAXC];
bool isReach[MAXR][MAXC];
int distR[8], distC[8];
int ansEven, ansOdd;

bool isIn(int r, int c) {
    return !(r < 0 || c < 0 || r >= R || c >= C);
}

void dfs(int r, int c) {
    if(!isIn(r,c) || mat[r][c] == -1)
        return;
    if(isReach[r][c])
        return;

    isReach[r][c] = true;
    for(int i=0;i<8;++i)
        dfs(r+distR[i], c+distC[i]);
}

int solve() {
    ansEven = ansOdd = 0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j) {
            if(mat[i][j] != -1 && isReach[i][j]) {
                int count = 0;
                set<pair<int, int> > dest;
                for(int k=0;k<8;++k) {
                    int nextR = i + distR[k];
                    int nextC = j + distC[k];
                    dest.insert(make_pair(nextR, nextC));
                }
                for(set<pair<int, int> >::iterator it=dest.begin();it!=dest.end();++it) {
                    int nextR = it->first;
                    int nextC = it->second;
                    if(isIn(nextR, nextC) && isReach[nextR][nextC] && mat[nextR][nextC] != -1)
                        ++count;
                }

                if(count%2==0)
                    ++ansEven;
                else
                    ++ansOdd;
            }
        }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        memset(mat, 0, sizeof(mat));
        scanf("%d %d %d %d %d", &R, &C, &M, &N, &W);
        distR[0] = M;
        distR[1] = M;
        distR[2] = -M;
        distR[3] = -M;
        distR[4] = N;
        distR[5] = N;
        distR[6] = -N;
        distR[7] = -N;

        distC[0] = N;
        distC[1] = -N;
        distC[2] = N;
        distC[3] = -N;
        distC[4] = M;
        distC[5] = -M;
        distC[6] = M;
        distC[7] = -M;
        for(int i=0;i<W;++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            mat[x][y] = -1;
        }
        
        memset(isReach, false, sizeof(isReach));
        dfs(0, 0);
        solve();
        printf("Case %d: %d %d\n", ii, ansEven, ansOdd);
    }
    
    return 0;
}
