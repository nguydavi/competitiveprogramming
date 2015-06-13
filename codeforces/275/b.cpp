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
const ll MAXC = 4e9+10;
int C1, C2, X, Y;

bool isGood(ll z) {
    ll numAB = z/(X*Y);
    ll numA = z/Y - numAB;
    ll numB = z/X - numAB;
    ll rest = z - numA - numB - numAB;
    //cout << "DEBUG " << numA << " " << numB << " " << rest << " " << numAB << endl;

    return rest - (max(0LL, C1 - numA)) >= 0 && (max(0LL, C2 - numB) <= rest - (max(0LL, C1 - numA)));
}

ll solve() {
    ll left = C1+C2;
    ll right = MAXC;
    while(left < right) {
        ll mid = (left+right)/2;
        if(isGood(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    while(cin >> C1 >> C2 >> X >> Y)
        cout << solve() << "\n";
    return 0;
}
