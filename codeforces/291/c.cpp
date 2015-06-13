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

const int MAXN = 6e5+10;
int N, M;

struct node {
    bool end;
    int child[3];

    node() {
        end = false;
        memset(child, -1, sizeof(child));
    }
};
node trie[MAXN];
int nxt = 1;

void addTrie(const string& s) {
    int cur = 0;
    for(int i=0;i<s.size();++i) {
        int c = s[i]-'a';
        if(trie[cur].child[c] == -1)
            trie[cur].child[c] = nxt++;
        cur = trie[cur].child[c];
    }
    trie[cur].end = true;
}

bool query(int cur, int index, int diff, const string& s) {
    if(diff > 1)
        return false;
    if(index == s.size())
        return diff == 1 && trie[cur].end;

    int c = s[index]-'a';
    for(int i=0;i<3;++i)
        if(trie[cur].child[i] != -1) {
            if(query(trie[cur].child[i], index+1, diff + (c != i), s))
                return true;
        }
    return false;
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        addTrie(s);
    }

    for(int i=0;i<M;++i) {
        string s;
        cin >> s;
        if(query(0, 0, 0, s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
