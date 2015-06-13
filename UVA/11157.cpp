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

const int MAXN = 110;
int N, D;
int arr[MAXN];
bool isBig[MAXN];

int solve() {
    if(!N)
        return D;
    if(N==1)
        if(isBig[0])
            return max(arr[0], D-arr[0]);
        else
            return D;

    int cur = 0, prev = 0;
    int ans = arr[0];
    while(cur < N) {
        ans = max(ans, arr[cur]-arr[prev]);
        prev = cur;
        if(isBig[cur+1] || (cur%2!=0))
            ++cur;
        else
            cur+=2;
    }
    ans = max(ans, D-arr[prev]);

    if(!isBig[0])
        ans = max(ans, arr[1]), cur = 1, prev = 1;
    else
        cur = 0, prev = 0;
    while(cur < N) {
        ans = max(ans, arr[cur]-arr[prev]);
        prev = cur;
        if(isBig[cur+1] || (cur%2==0))
            ++cur;
        else
            cur+=2;
    }
    ans = max(ans, D-arr[prev]);
    return ans;
}

int main() {
    int tt;
    scanf("%d", &tt);
    for(int ii=1;ii<=tt;++ii) {
        memset(isBig, false, sizeof(isBig));
        scanf("%d %d", &N, &D);
        for(int i=0;i<N;++i) {
            char c;
            scanf(" %c-%d", &c, &arr[i]);
            if(c == 'B')
                isBig[i] = true;
        }

        int ans = solve();
        printf("Case %d: %d\n", ii, ans);
    }    
    return 0;
}
