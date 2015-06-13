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

const string ss = "machula";

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string a, b, c;
        char d, e;
        cin >> a >> d >> b >> e >> c;

        if(a.find(ss) != a.npos) {
            int bInt = stoi(b);
            int cInt = stoi(c);
            int aInt = cInt - bInt;
            a = to_string(aInt);
        } else if(b.find(ss) != b.npos) {
            int aInt = stoi(a);
            int cInt = stoi(c);
            int bInt = cInt - aInt;
            b = to_string(bInt);
        } else {
            int aInt = stoi(a);
            int bInt = stoi(b);
            int cInt = aInt + bInt;
            c = to_string(cInt);
        }

        cout << a << " " << d << " " << b << " " << e << " " << c << "\n";
    }
    return 0;
}
