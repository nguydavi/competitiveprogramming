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

typedef unsigned long long ll;
ll N, L, U;

int main() {
    while(scanf("%lld %lld %lld", &N, &L, &U) == 3) {
        ll M = 0;
        for(ll i=(1LL<<32);i>0;i>>=1) {
            if((M|i) <= L || ((M|i) <= U && ~N & i))
                M |= i;
        }
        printf("%lld\n", M);
    }
    
    return 0;
}
