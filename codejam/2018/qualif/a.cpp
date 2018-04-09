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

ll damage(const string& P) {
    ll res = 0;
    ll curDamage = 1;
    for(char c : P) {
        if(c == 'C') {
            curDamage *= 2;
        } else if(c == 'S') {
            res += curDamage;
        }
    }
    return res;
}

ll solve(int D, string& P) {
    ll ans = 0;
    ll curDamage;
    while((curDamage = damage(P)) > D) {
        bool found = false;
        for(int index = P.size()-2; index >= 0; --index) {
            if(P[index] == 'C' && P[index+1] == 'S') {
                P[index] = 'S';
                P[index+1] = 'C';
                found = true;
                break;
            }
        }
        if(!found)
            break;
        ++ans;
    }

    if(curDamage > D)
        return -1;
    return ans;
}

int main() {
    int tt;
    cin >> tt;
    for(int ii=1;ii<=tt;++ii) {
        int D;
        string P;
        cin >> D >> P;
        ll ans = solve(D, P);

        cout << "Case #" << ii << ": ";
        if(ans == -1)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << endl;

    }
    return 0;
}
