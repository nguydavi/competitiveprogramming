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
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int sum = a+b+c+d+e;
    if(sum%5 == 0 && sum)
        cout << sum/5 << "\n";
    else
        cout << "-1\n";

    return 0;
}
