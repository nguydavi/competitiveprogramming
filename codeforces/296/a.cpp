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
ll A, B;

int main() {
    cin >> A >> B;
    ll ans = 0;
    while(A && B) {
        ans += A/B;
        ll newA = max(A%B, B);
        ll newB = min(A%B, B);
        A = newA;
        B = newB;
    }
    cout << ans << endl;
    return 0;
}
