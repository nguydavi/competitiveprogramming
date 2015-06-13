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

const int MAXB = 10010;
const int MAXS = 10010;
const int INF = (int)1e9;
int B, S;
int bb[MAXB], ss[MAXS];

int main() {
    int tc = 1;
    while(scanf("%d %d", &B, &S) && B && S) {
        for(int i=0;i<B;++i)
            scanf("%d", &bb[i]);
        for(int i=0;i<S;++i)
            scanf("%d", &ss[i]);
        sort(bb, bb+B);

        if(B <= S)
            printf("Case %d: 0\n", tc++);
        else
            printf("Case %d: %d %d\n", tc++, B-S, bb[0]);
    }    
    return 0;
}
