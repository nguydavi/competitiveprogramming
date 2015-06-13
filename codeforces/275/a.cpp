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
ll L, R;

int gcd(ll a, ll b) {
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main() {
    cin >> L >> R; 
    for(ll i=L; i<=R-2; ++i)
        for(ll j=i+1;j<=R-1; ++j)
            for(ll k=j+1;k<=R;++k) {
                if(gcd(i,j) == 1 && gcd(j,k) == 1 && gcd(i,k) != 1) {
                    cout << i << " " << j << " " << k << "\n";
                    return 0;
                }
            }
    cout << -1 << "\n";
    return 0;
}
