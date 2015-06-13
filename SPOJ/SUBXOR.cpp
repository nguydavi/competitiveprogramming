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
const int MAXL = (int)2e5;
int N, K;
int totalXOR;

int trie[MAXL][2];
int trieChildren[MAXL];
int trieSize;

void trieAdd(int a) {
    int cur = 1;
    for(int i=30;i>=0;--i) {
        ++trieChildren[cur]; // even if 2 subarrays have same XOR, there are still different subarrays
        int curBit = (a & (1<<i)) > 0;
        if(trie[cur][curBit] == 0)
            trie[cur][curBit] = ++trieSize;
        cur = trie[cur][curBit];
    }
}

ll trieQuery(int cur, int index, bool equal) {
    if(cur == 0 || index == -1)
        return 0LL;
    if(!equal)
        return trieChildren[cur];
    int curBit = (totalXOR & (1<<index)) > 0;
    int curKBit = (K & (1<<index)) > 0;

    ll res = 0;
    if(curKBit) {
        res += trieQuery(trie[cur][0], index-1, curBit^0);
        res += trieQuery(trie[cur][1], index-1, curBit^1);
    } else {
        if(curBit)
            res += trieQuery(trie[cur][1], index-1, true);
        else
            res += trieQuery(trie[cur][0], index-1, true);
    }
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &K);
        memset(trie, 0, sizeof(trie));
        memset(trieChildren, 0, sizeof(trieChildren));

        trieSize = 1;
        trieAdd(0);//for one element array as a^a = 0
                    //is counted only once in the trieChildren because for each
                    //subarray ending at ith element, we count the one array
                    //element only once

        totalXOR = 0;
        ll ans = 0;
        for(int i=0;i<N;++i) {
            int a;
            scanf("%d", &a);

            totalXOR ^= a;
            ans += trieQuery(1, 30, true);
            trieAdd(totalXOR);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
