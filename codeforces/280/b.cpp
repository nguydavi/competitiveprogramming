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

const int MAXN = 1010;
int N, L;
int arr[MAXN];
set<int> ss;

int main() {
    scanf("%d %d", &N, &L);
    for(int i=0;i<N;++i) {
        int a;
        scanf("%d", &a);
        ss.insert(a);
    }

    int ans = 0;
    if(*(ss.begin()) != 0)
        ans = max(ans, *(ss.begin()));
    if(*(ss.rbegin()) != L)
        ans = max(ans, L-*(ss.rbegin()));

    int diff = 0;
    int prev = *(ss.begin());
    for(set<int>::iterator it=ss.begin(); it!=ss.end();++it) {
        diff = max(diff, *it-prev);
        prev = *it;
    }

    double ansD = ans;
    printf("%.9lf\n", 1.*max(ansD, 1.*diff/2));
    return 0;
}
