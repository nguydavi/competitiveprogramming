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
int val[26];
map<ll, int> mm[26];
string s;
    
int main() {
    for(int i=0;i<26;++i)
        cin >> val[i];
    cin >> s;

    ll sum = 0;
    ll ans = 0;
    for(int i=0;i<s.size();++i) {
        int c = s[i]-'a';

        // if same character with same sum happened before, it means the
        // difference was 0 and sum of substring was 0.
        ans += mm[c][sum];

        sum += val[c];
        ++mm[c][sum];
    }
    cout << ans << "\n";

    return 0;
}
