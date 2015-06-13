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

const int MAXN = 200010;
int M, N;
vector<pair<int, pair<int, int> > > edgeList;
int sets[MAXN];
int total;

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
    while(scanf("%d %d", &N, &M) == 2 && (M || N)) {
        edgeList.clear();
        total = 0;
        for(int i=0;i<M;++i) {
            int u, v, z;
            scanf("%d %d %d", &u, &v, &z);
            edgeList.push_back(make_pair(z, make_pair(u, v)));
            total += z;
        }
        sort(edgeList.begin(), edgeList.end());
        for(int i=0;i<N;++i)
            sets[i] = i;

        int ans = 0;
        for(int i=0;i<edgeList.size();++i) {
           int u = edgeList[i].second.first; 
           int v = edgeList[i].second.second; 
           int z = edgeList[i].first;
           if(!isSameSet(u, v)) {
               ans += z;
               unionSet(u, v);
           }
        }

        printf("%d\n", total-ans);
    }    
    return 0;
}
