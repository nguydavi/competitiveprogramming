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

#define MAXX 110
int mat[MAXX][MAXX], sum[MAXX][MAXX];
int N;

void precompute() {
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(!i && !j)
                sum[i][j] = mat[i][j];
            else if(!i)
                sum[i][j] = sum[i][j-1] + mat[i][j];
            else  if(!j)
                sum[i][j] = sum[i-1][j] + mat[i][j];
            else
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + mat[i][j];
}

int getSubRectVal(int a, int b, int c, int d) {
    if(!a && !b)
        return sum[c][d];
    if(!a)
        return sum[c][d] - sum[c][b-1];
    if(!b)
        return sum[c][d] - sum[a-1][d];
    return sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
}

int solve() {
    int res = -200;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
           for(int k=i;k<N;++k)
              for(int m=j;m<N;++m) 
                  res = max(res, getSubRectVal(i, j, k, m));

    return res;
}

int main() {
    cin >> N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin >> mat[i][j];
    precompute();
    cout << solve() << "\n";

    return 0;
}
