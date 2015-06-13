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

int N;

int main() {
    string s;
    cin >> N >> s;

    set<char> ss;
    for(char c : s)
        ss.insert(tolower(c));

    if(ss.size() == 26)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
