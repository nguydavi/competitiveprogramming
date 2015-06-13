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
const int MAXN = 30;
int N;
ll fact[MAXN];
int cnt[26];

int nextChar(int letter) {
    for(int i=letter+1;i<26;++i)
        if(cnt[i])
            return i;
    return -1;
}

ll calc() {
    int len = 0;
    ll perm = 1;
    for(int i=0;i<26;++i) {
        len += cnt[i];
        perm *= fact[cnt[i]];
    }
    return fact[len]/perm;
}

string solve(ll k) {
    string res;
    int leftLen = N;
    while(leftLen) {
        int letter = -1;
        ll poss = 0, prevPoss = 0;
        while(poss < k) {
            letter = nextChar(letter);

            --cnt[letter];
            prevPoss = poss;
            poss += calc();
            ++cnt[letter];
        }

        res += char('a'+letter);
        k -= prevPoss;
        --cnt[letter];
        --leftLen;
    }
    return res;
}

int main() {
    fact[0] = 1;
    for(int i=1;i<MAXN;++i)
        fact[i] = fact[i-1]*i;

    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        string s;
        ll k;
        cin >> s >> k;

        N = s.size();
        sort(s.begin(), s.end());
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<N;++i)
            ++cnt[s[i]-'a'];
        if(k > calc()) {
            cout << "Case " << ii << ": Impossible\n";
            continue;
        }

        string ans = solve(k);
        cout << "Case " << ii << ": " << ans << "\n";
    }
    return 0;
}
