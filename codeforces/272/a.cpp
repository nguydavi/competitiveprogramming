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

int N, M;

int main() {
    cin >> N >> M;
    int mini = N/2;
    if(N%2 == 1)
        ++mini;

    if(N < M)
        cout << "-1\n";
    else if(mini%M != 0)
        cout << mini + M - mini%M << "\n";
    else
        cout << mini << "\n";
     
    return 0;
}
