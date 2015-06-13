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

typedef long long ll;
#define MAXS 30

int DEG, D,K;
int pol[MAXS];

ll eval(int n) {
    ll res = 0;
    ll base = 1;
    for(int i=0;i<=DEG;++i)
        res += base * pol[i], base *=n;
    return res;
}

ll solve() {
    int index = 0;
    int n = 1;
    while(1) {
        index += D*n;
        if(K <= index)
            return eval(n);
        ++n; 
    }
    return 0LL;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> DEG;
        for(int i=0;i<=DEG;++i)
            cin >> pol[i];

        cin >> D >> K;
        cout << solve() << "\n";
    }    
    return 0;
}
