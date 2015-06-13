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

const int MAXN = 110;
const int MAXM = MAXN*MAXN;
const int INF = (int)1e9;
int N, M;
deque<pair<int, pii> > edgeList;
int sets[MAXN];
bool edgeVis[MAXM];

void initSet() {
    for(int i=0;i<N;++i)
        sets[i] = i;
}

int findSet(int a) {
    if(sets[a] == a)
        return a;
    return sets[a] = findSet(sets[a]);
}

bool isSameSet(int a, int b) {
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b) {
    sets[findSet(b)] = findSet(a);
}

int solve(int ign) {
    int res = 0;
    initSet();
    for(int i=0;i<edgeList.size();++i) {
        if(i == ign)
            continue;

        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        int z = edgeList[i].first;

        if(!isSameSet(u, v)) {
            if(ign == -1)
                edgeVis[i] = true;
            unionSet(u, v);
            res += z;
        }
    }

    for(int i=1; i<N;++i)
        if(!isSameSet(0, i))
            return -1;

    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &N, &M);
        edgeList.clear();
        while(M--) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            --u;
            --v;
            edgeList.push_back(make_pair(z, make_pair(u, v)));
        }
        sort(edgeList.begin(), edgeList.end());

        memset(edgeVis, false, sizeof(edgeVis));
        int ans = solve(-1);
        printf("%d", ans);

        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<edgeList.size();++i)
            if(edgeVis[i]) {
                int rr = solve(i);
                if(rr != -1)
                    pq.push(rr);
            }
        printf(" %d\n", pq.top());
        
    } 
    return 0;
}
