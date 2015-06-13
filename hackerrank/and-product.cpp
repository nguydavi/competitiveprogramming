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

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        unsigned int a, b;
        scanf("%u %u", &a, &b);

        // longest common prefix is the answer
        unsigned int ans = 0;
        for(int i=31;i>=0;--i) {
            if((a>>i & 1) && (b>>i & 1))
                ans |= (1<<i);
            else if((a>>i & 1) != (b>>i & 1))
                break;
        }
        printf("%u\n", ans);
    }
    return 0;
}
