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

int A, B;

long long solve() {
    long long ans = 2;
    for(int i=0;i<A;++i) {
        ans*=ans;
        ans%=B;
    }
    return ans;
}

int main() {
    scanf("%d %d", &A, &B);
    printf("%lld\n", solve());
    return 0;
}
