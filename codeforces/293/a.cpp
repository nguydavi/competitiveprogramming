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
    string s, t;
    cin >> s >> t;

    bool ok = false;
    for(int i=s.size()-1;i>=0;--i) {
        char c = s[i]+1;
        if(c > 'z') {
            c = 'a';
            ok = true;
        }
        s[i] = c;
        
        if(!ok)
            break;
        ok = false;
    }

    if(s == t)
        cout << "No such string\n";
    else
        cout << s << "\n";
    return 0;
}
