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

const int MAXN = 300;
string s;
int dp[MAXN][MAXN];

bool isPal(int start, int end) {
    for(int i=0;i<=(end-start)/2;++i)
        if(s[start+i] != s[end-i])
            return false;
    return true;
}

void addPal(int start, int len, set<string>& pals) {
    string x = s.substr(start, len);
    for(string p : pals)
        if(p.find(x) != string::npos || x.find(p) != string::npos)
            return;
    pals.insert(x);
}

void removePal(int start, int end, set<string>& pals) {
    string x = s.substr(start, end+1);
    pals.erase(x);
}

bool solve(int start, int end, set<string>& pals) {
    if(start+2 > end)
        return false;
    if(dp[start][end] != -1)
        return dp[start][end];

    for(int i=2;start+i<=end;++i)
        if(isPal(start, start+i)) {
            addPal(start, i+1, pals);
            if(pals.size() == 2 || solve(start+i-1, end, pals)) {
                dp[start][end] = true;
                return true;
            }
            removePal(start, i+1, pals);
        }

    bool res = solve(start+1, end, pals);
    dp[start][end] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> s) {
        set<string> pals;
        memset(dp, -1, sizeof(dp));
        if(solve(0, s.size()-1, pals))
            cout << s << "\n";
    }
    return 0;
}
