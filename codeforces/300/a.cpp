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

int main() {
    string s;
    cin >> s;

    string expect = "CODEFORCES";
    int index = 0;
    int i = 0;
    int skipped = 0;
    while(s[i] != expect[index] && i < s.size())
        ++i;
    if(i != index)
        ++skipped;

    while(s[i] == expect[index] && i < s.size() && index < expect.size())
        ++i, ++index;

    string expectRem = expect.substr(index);
    string rem = s.substr(i);
    int is = rem.rfind(expectRem);

    if(is > 0)
        ++skipped;
    if(is+expectRem.size() < rem.size())
        ++skipped;

    if(is == string::npos || skipped > 1)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}
