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

#define MAXS 20000
struct row {
    string name;
    int low, high;
};
row db[MAXS];
int D;

string solve(int val) {
    string res("");
    for(int i=0;i<D;++i) {
        if(db[i].low <= val && val <= db[i].high)
            if(res == "")
                res = db[i].name;
            else
                return "UNDETERMINED";
    }
    if(res == "")
        return "UNDETERMINED";

    return res;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> D;
        for(int i=0;i<D;++i) {
            row tmp;
            cin >> tmp.name >> tmp.low >> tmp.high;
            db[i] = tmp;
        }
        int Q;
        cin >> Q;
        while(Q--) {
            int val;
            cin >> val;
            cout << solve(val) << "\n";
        }
        if(tc)
            cout << "\n";
    }
    return 0;
}
