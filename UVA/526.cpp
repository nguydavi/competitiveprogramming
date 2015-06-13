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

typedef pair<int, int> pii;
const int MAXN = 100;
int dp[MAXN][MAXN];
char op[MAXN][MAXN];
string a, b;

void display(int i, int j, int& cnt, int& ins, int& del) {
    if(i == 0 && j == 0)
        return;

    switch(op[i][j]) {
        case 'R':
            display(i-1, j-1, cnt, ins, del);
            cout << cnt++ << " Replace " << i+ins-del << "," << b[j-1] << "\n";
            break;
        case 'I':
            display(i, j-1, cnt, ins, del);
            cout << cnt++ << " Insert " << i+ins-del+1 << "," << b[j-1] << "\n";
            ++ins;
            break;
        case 'D':
            display(i-1, j, cnt, ins, del);
            cout << cnt++ << " Delete " << i+ins-del << "\n";
            ++del;
            break;
        default:
            display(i-1, j-1, cnt, ins, del);
    }
}

void solve() {
    for(int i=0;i<=a.size();++i) {
        dp[i][0] = i;
        op[i][0] = 'D';
    }
    for(int i=0;i<=b.size();++i) {
        dp[0][i] = i;
        op[0][i] = 'I';
    }

    for(int i=1;i<=a.size();++i)
        for(int j=1;j<=b.size();++j) {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = dp[i-1][j-1] + 1;
                op[i][j] = 'R';
            }

            if(dp[i-1][j] + 1 < dp[i][j]) {
                dp[i][j] = dp[i-1][j] + 1;
                op[i][j] = 'D';
            }
            if(dp[i][j-1] + 1 < dp[i][j]) {
                dp[i][j] = dp[i][j-1] + 1;
                op[i][j] = 'I';
            }
        }
}

int main() {
    bool first = true;
    while(getline(cin, a) && getline(cin, b)) {
        if(first)
            first = false;
        else
            cout << "\n";

        memset(op, 0, sizeof(op));
        solve();
        int ans = dp[a.size()][b.size()];
        cout << ans << "\n";

        int cnt = 1;
        int ins = 0;
        int del = 0;
        display(a.size(), b.size(), cnt, ins, del);
    }
    return 0;
}
