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
const int MAXN = 60;
int N;
char arr[MAXN][MAXN];
vector<pii> start;

bool isIn(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j) {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j] == 'o')
                start.push_back({i, j});
        }

    vector<pii> shifts;
    for(int dx=-N+1;dx<N;++dx)
        for(int dy=-N+1;dy<N;++dy) {
            bool ok = true;
            bool once = false;
            for(pii s : start) {
                int nx = s.first+dx;
                int ny = s.second+dy;
                if(isIn(nx, ny, N)) {
                    if(arr[nx][ny]  != '.')
                        ok &= true;
                    else
                        ok &= false;
                    once = true;
                }
            }
            if(ok && once) {
                shifts.push_back({dx, dy});
                for(pii s  : start) {
                    int nx = s.first+dx;
                    int ny = s.second+dy;
                    if(isIn(nx, ny, N)) {
                        arr[nx][ny] = 'd';
                    }
                }
            }
        }

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(arr[i][j] == 'x') {
                printf("NO\n");
                return 0;
            }

    vector< vector<char> > sol(2*N-1);
    for(int i=0;i<sol.size();++i)
        sol[i] = vector<char>(2*N-1, '.');

    for(pii shift : shifts) {
        int nx = N+shift.first-1;
        int ny = N+shift.second-1;
        if(isIn(nx, ny, 2*N-1))
            sol[nx][ny] = 'x';
    }
    sol[N-1][N-1] = 'o';
    printf("YES\n");
    for(int i=0;i<sol.size();++i) {
        for(int j=0;j<sol[i].size();++j)
            printf("%c", sol[i][j]);
        printf("\n");
    }
    return 0;
}
