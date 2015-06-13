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
const int MAXN = 1e5+10;
const int MAXL = 2e6+10;;
int N;
string arr[MAXN];

int nxt;
int trie[MAXL][26];

int addTrie(const string& s) {
    int res = 0;
    int cur = 0;
    for(int i=0;i<s.size();++i) {
        if(trie[cur][s[i]-'a'] == -1) {
            trie[cur][s[i]-'a'] = nxt++;
            if(res == 0)
                res = 1+i;
        }
        cur = trie[cur][s[i]-'a'];
    }
    if(res == 0)
        res = s.size();
    //cout << s.substr(0, res) << " ";
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int ii=1;ii<=tc;++ii) {
        memset(trie, -1, sizeof(trie));
        nxt = 1;

        scanf("%d", &N);
        ll ans = 0;
        for(int i=0;i<N;++i) {
            cin >> arr[i];
            ans += addTrie(arr[i]);
        }
        printf("Case #%d: %lld\n", ii, ans);
    }
    return 0;
}
