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

int N, M;

int main() {
    scanf("%d %d", &N, &M);

    int ans = 0;
    int n = N;
    int m = M;
    while(n && m && n+m >= 3) {
        if(n > m)
            n-=2, --m;
        else
            m-=2, --n;
        ++ans;
    }
    printf("%d\n", ans);

    return 0;
}
