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
int R, C;
char original[MAXR][MAXC];
char mat[MAXR][MAXC];

char dir[4] = {'<', '^', '>', 'v'};

bool simul(int r, int c) {
    char curDir = mat[r][c];
    int step = 0;
    while(step < 500) {
        if(curDir == dir[0])
            --c;
        else if(curDir == dir[1])
            --r;
        else if(curDir == dir[2])
            ++c;
        else if(curDir == dir[3])
            ++r;

        if(r < 0 || r >= R || c < 0 || c >= C)
            return false;
        ++step;
        if(mat[r][c] != '.')
            curDir = mat[r][c];
    }
    return true;
}

bool checkSol() {
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            if(!simul(i, j))
                return false;
    return true;
}

int countSol() {
    int result = 0;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
            result += (original[i][j] != mat[i][j]);
    return result;
}

int solve(int r, int c) {
    if(c == C) {
        if(checkSol()) {
            /*
            cout << "DEBUG: " << endl;
            for(int i=0;i<R;++i) {
                for(int j=0;j<C;++j)
                    cout << mat[i][j] << " ";
                cout << endl;
            }
            cout << countSol() << endl;
            return countSol();
            */
        } else
            return 500;
    }

    int result = 500;
    if(mat[r][c] != '.') {
        for(int i=0;i<4;++i) {
            mat[r][c] = dir[i];
            int nr = r+1;
            result = min(result, solve(nr%R, nr == R ? c+1 : c));
        }
    } else {
        int nr = r+1;
        result = min(result, solve(nr%R, nr == R ? c+1 : c));
    }

    return result;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d", &R, &C);
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j) {
                scanf(" %c", &mat[i][j]);
                original[i][j] = mat[i][j];
            }

        printf("Case %d: ", ii);
        int ans = solve(0, 0);
        if(ans == 500)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
