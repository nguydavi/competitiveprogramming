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

ll N;

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%lld", &N);
        ll N2 = N;
        
        int ans = 0;
        while(N2) {
            int dig = N2%10;
            if(dig && N%dig == 0)
                ++ans;
            N2/=10;
        }
        printf("%d\n", ans);
    }
    return 0;
}
