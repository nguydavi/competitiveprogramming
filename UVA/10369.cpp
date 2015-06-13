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

const int MAXN = 510;
int N, S;
pii vertexList[MAXN];
vector<pair<int, pii> > edgeList;
int sets[MAXN];

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

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &S, &N);
        for(int i=0;i<N;++i) {
            int x,y;
            scanf("%d %d", &x, &y);
            vertexList[i] = make_pair(x, y);
        }

        edgeList.clear();
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j) {
                int x = vertexList[i].first - vertexList[j].first;
                int y = vertexList[i].second - vertexList[j].second;
                edgeList.push_back(make_pair(x*x+y*y, make_pair(i, j)));
            }
        sort(edgeList.begin(), edgeList.end());

        vector<int> ans;
        initSet();
        for(int i=0;i<edgeList.size();++i) {
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int z = edgeList[i].first;

            if(!isSameSet(u, v)) {
                ans.push_back(z);
                unionSet(u, v);
            }
        }

        double D = sqrt(ans[N-1-S]);
        printf("%.2lf\n", D);

    } 
    return 0;
}
