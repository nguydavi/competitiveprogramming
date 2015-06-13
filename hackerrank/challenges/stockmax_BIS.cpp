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
const int MAXN = 50010;
int N;
int arr[MAXN];

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &N);
        for(int i=0;i<N;++i)
            scanf("%d", &arr[i]);

        ll ans = 0;
        int maxSoFar = 0;
        for(int i=N-1;i>=0;--i) {
            maxSoFar = max(maxSoFar, arr[i]);
            ans += maxSoFar - arr[i];
        }
        printf("%lld\n", ans);

    }
    return 0;
}
