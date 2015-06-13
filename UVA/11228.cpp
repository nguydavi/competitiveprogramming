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
typedef pair<int, int> pii;

const int MAXN = 1010;
int N, R;
pii vertexList[MAXN];
vector<pair<ll, pii> > edgeList;
bool edgeVis[MAXN*MAXN];
int sets[MAXN];

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
    for(int ii=1;ii<=tc;++ii) {
        scanf("%d %d", &N ,&R);
        for(int i=0;i<N;++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            vertexList[i] = make_pair(x, y);
        }

        edgeList.clear();
        for(int i=0;i<N;++i)
            for(int j=i+1;j<N;++j) {
                int x = vertexList[i].first - vertexList[j].first;
                int y = vertexList[i].second - vertexList[j].second;
                edgeList.push_back(make_pair(1LL * x*x + y*y, make_pair(i, j)));
            }
        sort(edgeList.begin(), edgeList.end());

        for(int i=0;i<N;++i)
            sets[i] = i;
        memset(edgeVis, false, sizeof(edgeVis));
        double roads = 0;
        double railroads = 0;
        int numStates = 1;
        for(int i=0;i<edgeList.size();++i) {
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int z = edgeList[i].first;

            if(!isSameSet(u, v)) {
                edgeVis[i] = true;
                unionSet(u, v);
                if(z <= R*R)
                    roads += sqrt(z);
                else
                    railroads += sqrt(z), ++numStates;
            }
        }

        /*
        for(int i=0;i<N;++i)
            sets[i] = i;
        for(int i=0;i<edgeList.size();++i) {
            if(edgeList[i].first <= R*R)
                unionSet(edgeList[i].second.first, edgeList[i].second.second);
        }
        set<int> states;
        for(int i=0;i<N;++i) {
            states.insert(sets[i]);
        }
        cout << endl;
        //int numStates = states.size();
        */

        printf("Case #%d: %d %d %d\n", ii, numStates, (int)round(roads), (int)round(railroads));
    }
    return 0;
}
