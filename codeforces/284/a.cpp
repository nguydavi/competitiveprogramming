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

int N, X;

int main() {
    scanf("%d %d", &N, &X);
    int cur = 1;
    int ans = 0;
    while(N--) {
        int left, right;
        scanf("%d %d", &left, &right);
        while(cur + X <= left)
            cur += X;
        ans += right - cur + 1;
        cur = right + 1;
    }
    printf("%d\n", ans);
    return 0;
}
