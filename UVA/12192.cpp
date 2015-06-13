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

#define MAXX 600
int N,M,Q,L,U;
int mat[MAXX][MAXX];

int getMaxSquare(int row, int size) {
    if(mat[row][M-1] < L || mat[row][0] > U)
        return -1;
        
    int left = 0, right = M-1;
    while(left < right) {
        int mid = (left+right)/2;
        if(mat[row][mid] < L)
            left = mid + 1;
        else if(mat[row][mid] >= L)
            right = mid;
    }
    int cornerRow = row;
    int cornerCol = left;
    if(mat[cornerRow][cornerCol] > U)
        return -1;

    if(cornerRow + size  < N && cornerCol + size < M) {
        left = size, right = min(N-1 - cornerRow, M-1 - cornerCol);
        if(mat[cornerRow+right][cornerCol+right] <= U)
            return right;

        while(left < right) {
            int mid = (left+right)/2;
            if(mat[cornerRow + mid][cornerCol + mid] <= U)
                left = mid + 1;
            else
                right = mid;
        }
        return max(0, left-1);
    }

    return size;
}

int solve() {
    int ans = -1;
    for(int i=0;i<N;++i)
        ans = max(ans, getMaxSquare(i, ans));

    return ans + 1;
}

int main() {
    while(cin >> N >> M && N && M) {
        for(int i=0;i<N;++i)
            for(int j=0;j<M;++j)
                cin >> mat[i][j];
        cin >> Q;
        while(Q--) {
            cin >> L >> U;
            cout << solve() << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
