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

const int MAXN = (int)1e5+10;
int b[MAXN];

/**
 * Do KMP with 's' and its reverse 'rs'. At the end of kmpSearch return index
 * where the search has ended, the index is the start of substring or 'rs' to be
 * added.
 */
void kmpPre(const string& s) {
    int i=0;
    int j=-1;
    b[0]=-1;

    while(i < s.size()) {
        while(j >= 0 && s[i] != s[j])
            j = b[j];
        ++i;
        ++j;
        b[i] = j;
    }
}

int kmpSearch(const string& t, const string& s) {
    int i=0;
    int j=0;

    while(i < t.size()) {
        while(j >= 0 && t[i]!=s[j])
            j = b[j];
        ++i;
        ++j;
    }
    return j;
}

int main() {
    string s;
    while(cin >> s) {
        string rs(s.rbegin(), s.rend());
        kmpPre(rs);

        string toAdd = rs.substr(kmpSearch(s ,rs));
        cout << s << toAdd << "\n";
    }
    return 0;
}
