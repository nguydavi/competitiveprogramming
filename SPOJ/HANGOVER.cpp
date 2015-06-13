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
    double K;
    while(scanf("%lf", &K) == 1 && K > 0.) {
        double sum = 0;
        int res = 0;
        while(sum < K) {
            ++res;
            sum += 1./(res+1);
        }
        printf("%d card(s)\n", res);
    }
    return 0;
}
