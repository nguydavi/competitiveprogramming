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

const int MAXN = 30;
const int MAXS = 300;
int N;
int arr[MAXN];
bool dp[MAXN][MAXS];

bool solve(int sum) {
    memset(dp, false, sizeof(dp));
    for(int i=0;i<=N;++i)
        dp[i][0] = true;

    for(int i=1;i<=N;++i)
        for(int j=arr[i-1];j<=sum;++j)
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];

    return dp[N][sum];
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int x;
        N = 0;
        int total = 0;
        while(ss >> x) {
            arr[N++] = x;
            total += x;
        }
        if(total%2 == 1) {
            printf("NO\n");
            continue;
        }

        if(solve(total/2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
