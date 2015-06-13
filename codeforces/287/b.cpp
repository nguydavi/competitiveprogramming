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

int R, X1, Y1, X2, Y2;

int main() {
    scanf("%d %d %d %d %d", &R, &X1, &Y1, &X2, &Y2);
    int ans = abs(Y2-Y1) + abs(X2-X1);
    int add = 0;
    if(ans % (2*R) != 0)
        add = 1;
    ans /= 2*R;
    ans += add;
    printf("%d\n", ans);
    return 0;
}
