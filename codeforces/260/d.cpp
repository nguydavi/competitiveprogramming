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

const int MAXN = (int)2e5+10;
int N, K;
int trie[MAXN][26];
int trieSize;

bool win[MAXN], lose[MAXN];

void solve() {
    for(int i=trieSize;i >= 0; --i) {
        bool isLeaf = true;
        for(int j=0;j<26;++j)
            if(trie[i][j] != 0) {
                isLeaf = false;
                break;
            }

        if(isLeaf) {
            win[i] = false;
            lose[i] = true;
        } else {
            win[i] = false;
            lose[i] = false;
            for(int j=0;j<26;++j)
                if(trie[i][j] != 0) {
                    win[i] |= !win[trie[i][j]];
                    lose[i] |= !lose[trie[i][j]];
                }
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    memset(trie, 0, sizeof(trie));
    trieSize = 1;
    while(N--) {
        string word;
        cin >> word;

        int cur = 1;
        for(int i=0;i<word.size();++i) {
            int x = word[i]-'a';
            if(trie[cur][x] == 0)
                trie[cur][x] = ++trieSize;
            cur = trie[cur][x];
        }
    }

    solve();

    if(!win[1])
        printf("Second\n");
    else if(lose[1])
        printf("First\n");
    else
        if(K%2==0)
            printf("Second\n");
        else
            printf("First\n");
    return 0;
}
