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
ll A,B,a,b;
const ll MOD = 1000000007;

int main() {
    cin >> A >> B;
    ll p = B*(B-1)/2 %MOD;
    ll q = A*(A+1)/2%MOD *B%MOD +A %MOD;
    cout << p*q%MOD << "\n";
    return 0;
}
