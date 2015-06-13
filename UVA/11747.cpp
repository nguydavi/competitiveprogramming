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
const int MAXN = 1010;
const int MAXM = 25010;
int N, M;
vector<pair<int, pii> > edgeList;
int sets[MAXN];
bool edgeVis[MAXM];

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

int main() {
    while(scanf("%d %d", &N, &M) == 2 && (N || M)) {
        edgeList.clear();
        memset(edgeVis, false, sizeof(edgeVis));
        for(int i=0;i<N;++i)
            sets[i] = i;

        for(int i=0;i<M;++i) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            edgeList.push_back(make_pair(z, make_pair(u, v)));
        }
        sort(edgeList.begin(), edgeList.end());

        for(int i=0;i<edgeList.size();++i) {
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int z = edgeList[i].first;

            if(!isSameSet(u, v)) {
                unionSet(u, v);
                edgeVis[i] = true;
            }
        }

        vector<int> ans;
        for(int i=0;i<edgeList.size();++i)
            if(!edgeVis[i])
                ans.push_back(edgeList[i].first);
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();++i) {
            if(i)
                printf(" ");
            printf("%d", ans[i]);
        }

        if(ans.empty())
            printf("forest");
        printf("\n");
            
    }    
    return 0;
}
