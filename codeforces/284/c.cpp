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

typedef long long ll;
int Ax, Ay, Bx, By, N;

int sign(ll a) {
    return a < 0 ? -1 : !!a;
}

int main() {
    scanf("%d %d", &Ax, &Ay);
    scanf("%d %d", &Bx, &By);
    scanf("%d", &N);

    int ans = 0;
    while(N--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int signA = sign(ll(a)*Ax + ll(b)*Ay+c);
        int signB = sign(ll(a)*Bx + ll(b)*By+c);
        if(signA != signB)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
