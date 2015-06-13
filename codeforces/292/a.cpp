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
ll X, Y, S;

int main() {
    cin >> X >> Y >> S;
    X = abs(X);
    Y = abs(Y);
    if(S < X+Y || (S-X-Y)%2 != 0)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}
