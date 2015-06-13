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
const int MAXN = (int)2e5+10;
int N;
vector<int> p1, p2;

int main() {
    scanf("%d", &N);
    ll sum1 = 0, sum2 = 0;
    int last = 0;
    while(N--) {
        int a;
        scanf("%d", &a);
        if(a > 0)
            p1.push_back(a), sum1 += a;
        else
            p2.push_back(-a), sum2 += -a;
        last = a;
    }

    if(sum1 > sum2)
        printf("first\n");
    else if(sum2 > sum1)
        printf("second\n");
    else {
        if(p1 < p2)
            printf("second\n");
        else if(p1 > p2)
            printf("first\n");
        else {
            if(last < 0)
                printf("second\n");
            else
                printf("first\n");
        }
    }
    return 0;
}
