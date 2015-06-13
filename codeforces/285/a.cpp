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

int a, b, c, d;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int scoreM = max(75*a, 250*a - a*c);
    int scoreV = max(75*b, 250*b - b*d);
    if(scoreM == scoreV)
        printf("Tie\n");
    else if(scoreM < scoreV)
        printf("Vasya\n");
    else
        printf("Misha\n");
    return 0;
}
