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

const int MAXN = 210;
int N, M;
bool adj[MAXN][MAXN];
bool boys[MAXN], girls[MAXN];

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int main() {
    memset(adj, false, sizeof(adj));
    memset(boys, false, sizeof(boys));
    memset(girls, false, sizeof(girls));

    scanf("%d %d", &N, &M);
    int n, m;
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        boys[x] = true;
    }
    scanf("%d", &m);
    while(m--) {
        int x;
        scanf("%d", &x);
        girls[x] = true;
    }

    for(int i=0;i<=2*N*M;++i)
        boys[i%N] = girls[i%M] = boys[i%N] || girls[i%M];

    for(int i=0;i<N;++i)
        if(!boys[i]) {
            printf("No\n");
            return 0;
        }
    for(int i=0;i<M;++i)
        if(!girls[i]) {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}
