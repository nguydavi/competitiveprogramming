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

int K;

bool isPal(const string& s, int start, int end) {
    for(int i=0;i<=(end-start)/2;++i) {
        if(s[start+i] != s[end-1-i])
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s >> K;

    if(s.size() % K != 0) {
        cout << "NO\n";
        return 0;
    }
    int sz = s.size()/K;

    int cur = 0;
    while(cur < s.size()) {
        if(!isPal(s, cur, cur+sz)) {
            cout << "NO\n";
            return 0;
        }
        cur += sz;
    }
    cout << "YES\n";
    return 0;
}
