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

const int MAXN = 20;
int mat[MAXN][MAXN];
int N;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        mat[0][i] = 1;
        mat[i][0] = 1;
    }

    int ans = 1;
    for(int i=1;i<N;++i)
        for(int j=1;j<N;++j) {
            mat[i][j] = mat[i-1][j] + mat[i][j-1];
            ans = max(ans, mat[i][j]);
        }
    printf("%d\n", ans);
    return 0;
}
