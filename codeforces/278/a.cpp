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

bool hasEight(int a) {
    a = abs(a);
    while(a) {
        if((a%10) == 8)
            return true;
        a /= 10;
    }
    return false;
}

int main() {
    int a;
    scanf("%d", &a);

    int start = a+1;
    while(!hasEight(start))
        ++start;

    printf("%d\n", start-a);

    return 0;
}
