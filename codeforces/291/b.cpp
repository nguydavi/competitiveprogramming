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

const int MAXN = 1010;
int N, X, Y;
int px[MAXN], py[MAXN];
int parent[MAXN];

int findSet(int a) {
    if(parent[a] == a)
        return a;
    return parent[a]=findSet(parent[a]);
}

void unionSet(int a, int b) {
    parent[findSet(a)] = findSet(b);
}

int main() {
    scanf("%d %d %d", &N, &X, &Y);
    for(int i=0;i<N;++i)
        parent[i] = i;

    for(int i=0;i<N;++i)
        scanf("%d %d", &px[i], &py[i]);

    for(int i=0;i<N;++i) {
        double A = X!=px[i] ? (1.*Y-py[i])/(1.*X-px[i]) : 1e9;
        double B = 1.*Y - A*X;
        for(int j=i+1;j<N;++j) {
            if(X==px[i] && X==px[j])
                unionSet(i, j);
            else if(fabs(1.*py[j] - A*px[j]-B) < 1e-6)
                unionSet(i, j);
        }
    }

    set<int> ans;
    for(int i=0;i<N;++i)
        ans.insert(findSet(i));
    printf("%d\n", ans.size());
    return 0;
}
