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

int N;

int main() {
    scanf("%d", &N);
    int sum = 0;
    int cur = 0;
    while(N > 0) {
        ++cur;
        sum += cur;
        N -= sum;
    }
    if(N < 0)
        --cur;
    printf("%d\n", cur);
    return 0;
}
