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

const int MAXN = 510;
int N, M, Q;
int arr[MAXN][MAXN];
int maxPerRow[MAXN];

int computeMax(int row) {
    int result = 0;
    int cur = 0;
    for(int i=0;i<M;++i) {
        if(arr[row][i] == 1) {
            ++cur;
            result = max(result, cur);
        } else
            cur = 0;
    }
    return result;
}

int solveSimple() {
    int curMax = 0;
    for(int i=0;i<N;++i)
        curMax = max(curMax, maxPerRow[i]);
    return curMax;
}

int solveFull() {
    int curMax = 0;
    for(int i=0;i<N;++i) {
        maxPerRow[i] = computeMax(i);
        curMax = max(curMax, maxPerRow[i]);
    }
    return curMax;
}

int main() {
    memset(arr, 0, sizeof(arr));
    memset(maxPerRow, 0, sizeof(maxPerRow));
    scanf("%d %d %d", &N, &M, &Q);
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            scanf(" %d", &arr[i][j]);

    solveFull();
    while(Q--) {
        int r, c;
        scanf("%d %d", &r, &c);
        --r; --c;
        if(arr[r][c] == 1)
            arr[r][c] = 0;
        else
            arr[r][c] = 1;

        maxPerRow[r] = computeMax(r);
        printf("%d\n", solveSimple());
    }
    return 0;
}
