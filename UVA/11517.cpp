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

const int MAXN = 200;
const int MAXP = 10010;
const int INF = 1<<30;
int N, price;
int arr[MAXN];
int dp[MAXP];

void solve() {
    memset(dp, 0, sizeof(dp));
    for(int j=0;j<MAXP;++j)
        dp[j] = INF;
    dp[0] = 0;

    for(int i=0;i<N;++i)
        for(int j=MAXP-1;j>=arr[i];--j)
            if(dp[j-arr[i]] < INF)
                dp[j] = min(dp[j], dp[j-arr[i]] + 1);
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> price >> N;
        for(int i=0;i<N;++i)
            cin >> arr[i];
        solve();
        for(int p=price; p<MAXP;++p) {
            if(dp[p] < INF) {
                cout << p << " " << dp[p] << "\n";
                break;
            }
        }
    }    
    return 0;
}
