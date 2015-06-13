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
    int prevD, prevH, curD, curH;
    scanf("%d %d", &prevD, &prevH);
    int m = M-1;

    int ans = prevH + prevD - 1;
    curD = prevD;
    curH = prevH;
    while(m--) {
        scanf("%d %d", &curD, &curH);
        if(abs(curH-prevH) > abs(curD-prevD)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        int diff = abs(curD-prevD)-abs(curH-prevH)-1;

        ans = max(ans, max(curH, prevH) + (diff+1)/2 );
        prevD = curD;
        prevH = curH;
    }
    ans = max(ans, curH + N-curD);

    printf("%d\n", ans);
    return 0;
}
