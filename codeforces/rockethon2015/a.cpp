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

int N1, N2, K1, K2;

int main() {
    scanf("%d %d %d %d", &N1, &N2, &K1, &K2);
    if(N1 <= N2)
        printf("Second\n");
    else
        printf("First\n");
    return 0;
}
