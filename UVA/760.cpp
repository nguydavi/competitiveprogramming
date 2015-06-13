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

const int MAXN = (int)1e6;
string a, b;
int trie[MAXN][4];
int nxt;
map<char, int> mm;

void addTrie(int start, const string& a) {
    int cur = 0;
    for(int i=start;i<a.size();++i) {
        int c = mm[a[i]];
        if(trie[cur][c] == -1)
            trie[cur][c] = nxt++;
        cur = trie[cur][c];
    }
}

int longestPrefix(int start, const string& b) {
    int cur = 0;
    int res = 0;
    for(int i=start;i<b.size();++i) {
        int c = mm[b[i]];
        if(trie[cur][c] == -1)
            break;
        ++res;
        cur = trie[cur][c];
    }
    return res;
}

int main() {
    mm['a'] = 0;
    mm['c'] = 1;
    mm['g'] = 2;
    mm['t'] = 3;

    int tc = 0;
    while(cin >> a >> b) {
        if(tc++)
            cout << "\n";
        memset(trie, -1, sizeof(trie));
        nxt = 1;
        for(int i=0;i<a.size();++i)
            addTrie(i, a);

        set<string> sols;
        int ans = 0;
        for(int i=0;i<b.size();++i) {
            int tt = longestPrefix(i, b);
            ans = max(ans, tt);
            sols.insert(b.substr(i, tt));
        }

        if(ans == 0) {
            cout << "No common sequence.\n";
            continue;
        }
        for(set<string>::iterator it=sols.begin();it!=sols.end();++it)
            if(it->size() == ans)
                cout << *it << "\n";
    }
    return 0;
}
