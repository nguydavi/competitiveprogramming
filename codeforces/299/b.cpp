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

int N;

int cntDigit(int n) {
    int res = 0;
    while(n) {
        ++res;
        n/=10;
    }
    return res;
}

void solve(int n, int left, set<int>& v) {
    if(left == 0) {
        v.insert(n);
        return;
    }

    solve(n*10+4, left-1, v);
    solve(n*10+7, left-1, v);
}

int main() {
    scanf("%d", &N);
    int digits = cntDigit(N);
    int ans = (1<<digits) - 2;

    set<int> sol;
    solve(0, digits, sol);
    int i = 0;
    for(int x : sol) {
        if(x == N)
            ans += i+1;
        ++i;
    }

    printf("%d\n", ans);
    return 0;
}
