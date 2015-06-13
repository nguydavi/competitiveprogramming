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
typedef pair<ll, ll> pll;
const int MAXN = 6e5+10;
const int BASE1 = 31;
const int BASE2 = 313;
const int MOD = 1e9+7;
int N, M;
set<pll> hh;
ll pw1[MAXN], pw2[MAXN];

/**
 * No element should be zero, that is why (c-'a'+1) and not (c-'a')
 * otherwise hash("b") == hash("baa")
 */
ll hash1(const string& s) {
    ll res = 0;
    for(char c : s)
        res = (res*BASE1 + (c-'a'+1)) % MOD;
    return res;
}

ll hash2(const string& s) {
    ll res = 0;
    for(char c : s)
        res = (res*BASE2 + (c-'a'+1)) % MOD;
    return res;
}

int main() {
    pw1[0] = pw2[0] = 1;
    for(int i=1;i<MAXN;++i) {
        pw1[i] = (pw1[i-1] * BASE1)%MOD;
        pw2[i] = (pw2[i-1] * BASE2)%MOD;
    }

    cin >> N >> M;
    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        hh.insert({hash1(s), hash2(s)});
    }

    while(M--) {
        string s;
        cin >> s;

        bool ok = false;
        ll sh1 = hash1(s);
        ll sh2 = hash2(s);
        for(int i=0;i<s.size();++i) {
            for(int j=0;j<3;++j) {
                if(s[i] == ('a'+j))
                    continue;
                char c = 'a'+j;

                /**
                 * ex:
                 * hash(abc) = BASE^2 + 2 * BASE + 3
                 * hash(acc) = BASE^2 + 3 * BASE + 3
                 * -> diff = 1 * BASE
                 *
                 * we add the difference of the ith character multiplied by the
                 * base
                 */
                ll nh1 = ((sh1 + pw1[s.size()-1-i] * (c-s[i])) % MOD + MOD) % MOD;
                ll nh2 = ((sh2 + pw2[s.size()-1-i] * (c-s[i])) % MOD + MOD) % MOD;
                if(hh.find({nh1, nh2}) != hh.end()) {
                    ok = true;
                    break;
                }
            }

            if(ok)
                break;
        }

        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
