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
const int MAXN = 70000;
int N;
set<pii> edgeList;
int deg[MAXN], vxor[MAXN];

void solve() {
    queue<int> q;
    for(int i=0;i<N;++i)
        if(deg[i] == 1)
            q.push(i);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(deg[cur] == 1) {
            int nxt = vxor[cur];
            edgeList.insert(pii(min(cur, nxt), max(cur, nxt)));
            --deg[nxt];
            vxor[nxt]^=cur;
            if(deg[nxt] == 1)
                q.push(nxt);
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i)
        scanf("%d %d", &deg[i], &vxor[i]);

    solve();

    printf("%d\n", (int)edgeList.size());
    for(pii edge : edgeList)
        printf("%d %d\n", edge.first, edge.second);
    return 0;
}
