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

int A, B;

set<int> findDiv(int n) {
    set<int> res;
    for(int i=1;i*i <= n;++i)
        if(n%i == 0) {
            res.insert(i);
            res.insert(n/i);
        }
    return res;
}

int main() {
    scanf("%d %d", &A, &B);
    if(B > A)
        printf("0\n");
    else if(A==B)
        printf("infinity\n");
    else {
        set<int> divisors = findDiv(A-B);
        int ans = 0;
        for(set<int>::iterator it=divisors.begin();it!=divisors.end();++it)
            if(A%*it==B)
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
