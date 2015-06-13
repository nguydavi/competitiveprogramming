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
int dp[MAXN][MAXS];

bool solve(int index, int sum) {
    if(index < 0 || sum < 0)
        return false;
    if(sum == 0)
        return true;
    if(dp[index][sum] != -1)
        return dp[index][sum];

    bool res = solve(index-1, sum);
    res = res || solve(index-1, sum-arr[index]);

    dp[index][sum] = res;
    return res;
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

        memset(dp, -1, sizeof(dp));
        if(solve(N-1, total/2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
