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

int N, M;

ll friendship(int x) {
    ll ans = x;
    ans *= (x-1);
    ans /= 2;
    return ans;
}


int main() {
    cin >> N >> M;

    cout << friendship(N/M+1)*(N%M) + friendship(N/M)*(M-N%M) << " ";
    cout << friendship(N-M+1) << "\n";
    return 0;
}
