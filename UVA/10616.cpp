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

#define MAXN 210
#define MAXM 20
#define MAXD 30
int N, Q, D, M;
int arr[MAXN];
ll dp[MAXN][MAXM][MAXD];

void solve() {
    for(int i=0;i<=N;++i)
        dp[i][0][0] = 1;

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            for(int k=0;k<D;++k) {
                int r = ((k-arr[i-1])%D+D)%D;
                dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][r];
            }
}

int main() {
    int tc = 1;
    while(cin >> N >> Q && N && Q) {
        for(int i=0;i<N;++i)
            cin >> arr[i];
        cout << "SET " << tc++ << ":\n";

        for(int ii=1;ii<=Q;++ii) {
            cin >> D >> M;

            solve();
            cout << "QUERY " << ii << ": " << dp[N][M][0] << "\n";
        }
    }
    
    return 0;
}
