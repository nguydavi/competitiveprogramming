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
const int MAXN = 2e5+10;
ll N, A, S;
ll dice[MAXN];

int main() {
    cin >> N >> A;
    for(int i=0;i<N;++i) {
        cin >> dice[i];
        S += dice[i];
    }

    for(int i=0;i<N;++i) {
        if(i)
            cout << " ";

        ll t = (min(dice[i], A-(N-1)) - (max(1LL, A-(S-dice[i]))) + 1);
        dice[i] -= t;
        cout << dice[i];
    }

    return 0;
}
