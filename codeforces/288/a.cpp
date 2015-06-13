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

const int MAXN = 1010;
int N, M, K;
bool mat[MAXN][MAXN];

bool lose(int a, int b) {
    if(a+1 < N && b+1 < M && mat[a][b+1] && mat[a+1][b] && mat[a+1][b+1])
        return true;
    if(a+1 < N && b > 0 && mat[a][b-1] && mat[a+1][b-1] && mat[a+1][b])
        return true;
    if(a > 0 && b+1 < M && mat[a-1][b] && mat[a-1][b+1] && mat[a][b+1])
        return true;
    if(a > 0 && b > 0 && mat[a-1][b-1] && mat[a-1][b] && mat[a][b-1])
        return true;
    return false;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int ans = 0;
    memset(mat, false, sizeof(mat));
    for(int i=1;i<=K;++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;

        if(ans == 0 && lose(a, b))
            ans = i;
        mat[a][b] = true;
    }
    printf("%d\n", ans);
    return 0;
}
