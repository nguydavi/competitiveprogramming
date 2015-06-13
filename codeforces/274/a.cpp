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

int a,b,c;

int main() {
    cin >> a >> b >> c;
    int ans = 0;    
    ans = max(a+b+c, a*b*c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    cout << ans << "\n";
    return 0;
}
