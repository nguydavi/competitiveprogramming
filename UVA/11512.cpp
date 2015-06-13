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

typedef pair<int, int> pii;
typedef pair<string, int> psi;
const int MAXLEN = 1010;
string a;
map<char, int> mm;
char nn[] = {'A', 'C', 'G', 'T'};

int trie[MAXLEN*MAXLEN][4];
int cnt[MAXLEN*MAXLEN];
int nxt;
set<psi> sols;
int maxLen;

void addTrie(int start, const string& a) {
    int cur = 0;
    for(int i=start;i<a.size();++i) {
        if(trie[cur][mm[a[i]]] == -1)
            trie[cur][mm[a[i]]] = nxt++;
        cur = trie[cur][mm[a[i]]];
        ++cnt[cur];
    }
}

void dfs(int cur, int rep, const string a) {
    int maxRep = 0;
    for(int i=0;i<4;++i)
        if(trie[cur][i] > 0)
            maxRep = max(maxRep, cnt[trie[cur][i]]);

    if(maxRep <= 1) {
        maxLen = max(maxLen, (int)a.size());
        sols.insert(psi(a, rep));
    } else
        for(int i=0;i<4;++i)
            if(trie[cur][i] > 0 && cnt[trie[cur][i]] > 1)
                dfs(trie[cur][i], cnt[trie[cur][i]], a+nn[i]);
}

int main() {
    mm['A'] = 0;
    mm['C'] = 1;
    mm['G'] = 2;
    mm['T'] = 3;

    int tc;
    scanf("%d", &tc);
    while(tc--) {
        nxt = 1;
        memset(cnt, 0, sizeof(cnt));
        memset(trie, -1, sizeof(trie));
        sols.clear();

        cin >> a;
        for(int i=0;i<a.size();++i)
            addTrie(i, a);

        int maxRep = 0;
        for(int i=0;i<4;++i)
            if(trie[0][i] > 0)
                maxRep = max(maxRep, cnt[trie[0][i]]);

        if(maxRep == 1)
            cout << "No repetitions found!\n";
        else {
            maxLen = 0;
            dfs(0, -1, "");
            for(set<psi>::iterator it=sols.begin();it!=sols.end();++it)
                if(it->first.size() == maxLen) {
                    cout << it->first << " " << it->second << "\n";
                    break;
                }
        }
    }
    return 0;
}
