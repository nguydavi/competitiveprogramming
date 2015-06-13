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

const int MAXX = 2000;
const int INF = (int)1e9;
const int CLIMB = 60, STAY = 30, SINK = 20;
int N, X;
int wind[MAXX][13], dp[MAXX][13];

int solve() {
    for(int i=0;i<=X;++i)
        for(int j=0;j<10;++j)
            dp[i][j] = INF;
    dp[0][0] = 0;

    for(int i=1;i<=X;++i) 
        for(int j=0;j<10;++j) {
            dp[i][j] = dp[i-1][j] + STAY - wind[i-1][j];
            if(j<9)
                dp[i][j] = min(dp[i][j], dp[i-1][j+1] + SINK - wind[i-1][j+1]);
            if(j)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + CLIMB - wind[i-1][j-1]);
        }
}

int main() {
    cin >> N;
    while(N--) {
        cin >> X;
        X /= 100;
        for(int j=9;j>=0; --j)
            for(int i=0;i<X;++i)
                cin >> wind[i][j];

        solve();
        cout << dp[X][0] << "\n";
        cout << "\n";

    }    
    return 0;
}
