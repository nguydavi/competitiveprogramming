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
int N, X, Y;

// Vanya shoots at 1/X and Vova 1/Y, if we multiply both by X*Y, we have Vanya
// shooting one every Y seconds and Vova one every X seconds
void solve(ll a) {
    ll left = 1;
    ll right = (ll)1e15;
    while(left < right) {
        ll mid = (left+right)/2;
        if(mid/X+mid/Y < a)
            left = mid+1;
        else
            right = mid;
    }

    if(left%X == 0 && left%Y == 0)
        printf("Both\n");
    else if(left%Y == 0)
        printf("Vanya\n");
    else
        printf("Vova\n");
}

int main() {
    scanf("%d %d %d", &N, &X, &Y);
    while(N--) {
        int a;
        scanf("%d", &a);
        solve(a);
    }
    return 0;
}
