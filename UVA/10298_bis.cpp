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

const int MAXN = (int)1e6+10;
int b[MAXN];

void kmpPre(const string& s) {
    int i = 0;
    int j = -1;
    b[0] = -1;

    while(i < s.size()) {
        while(j>=0 && s[i]!=s[j])
            j = b[j];
        ++i;
        ++j;
        b[i] = j;
    }
}

int kmpSearch(const string& t, const string&s, int start) {
    int i = start;
    int j = 0;

    while(i < t.size()) {
        while(j>=0 && t[i]!=s[j])
            j = b[j];

        ++i;
        ++j;
        if(j == s.size())
            return i-j;
    }
}

/**
 * KMP search on s+s starting at index 1, because we want to find the longest prefix
 * for which the string is repeating. 
 */
int main() {
    string s;
    while(cin >> s && s != ".") {
        kmpPre(s);
        string t = s+s;
        cout << s.size() / kmpSearch(t, s, 1) << "\n";
    }
    return 0;
}
