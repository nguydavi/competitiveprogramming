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

int M, S;
string mini, maxi;

void solve() {
    mini = string(M, '0');
    int rest = S-1;
    for(int i=M-1; i>0 && rest > 0; --i) {
        mini[i] = (char)('0' + min(9, rest));
        rest -= 9;
    }

    if(rest >= 0)
        mini[0] = (char)('1'+rest);
    else
        mini[0] = '1';

    maxi = string(M, '0');
    rest = S;
    for(int i=0; i<M && rest > 0; ++i) {
        maxi[i] = (char)('0' + min(9, rest));
        rest -= 9;
    }
}

int main() {
    scanf("%d %d", &M, &S);
    if(M == 1 && S == 0) {
        cout << "0 0\n";
        return 0;
    }
    if(S == 0 || S > 9*M) {
        cout << "-1 -1\n";
        return 0;
    }

    solve();
    cout << mini << " " << maxi << "\n";
    return 0;
}
