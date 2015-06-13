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

const int MAXN = 30;
int N;
int GP, GC, GF;
int arr[MAXN][3];

bool solve(int index, int p, int c, int f) {
    if(p == GP && c == GC && f == GF)
        return true;
    if(index == N || p > GP || c > GC || f > GF)
        return false;

    bool r1 = solve(index+1, p, c, f);
    bool r2 = solve(index+1, p+arr[index][0], c+arr[index][1], f+arr[index][2]);
    return r1 || r2;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d %d", &GP, &GC, &GF);
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        if(solve(0, 0, 0, 0))
            printf("Case #%d: yes\n", ii);
        else
            printf("Case #%d: no\n", ii);
    }

    return 0;
}
