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

bool solve(const string& s) {
    int index = 0;
    if(s[index] != '?')
        return false;

    while(index < s.size() && s[index] == '?')
        ++index;
    if(index == s.size() || s[index] != 'M')
        return false;
    int x = index;

    ++index;
    while(index < s.size() && s[index] == '?')
        ++index;
    if(index == s.size() || s[index] != 'E')
        return false;
    int y = index - x - 1;

    ++index;
    while(index < s.size() && s[index] == '?')
        ++index;
    if(index != s.size())
        return false;
    int z = (index - x - y - 2) - x;

    return y > 0 && y == z;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        string st;
        cin >> st;
        bool ans = solve(st);
        if(ans)
            printf("theorem\n");
        else
            printf("no-theorem\n");
    }
    return 0;
}
