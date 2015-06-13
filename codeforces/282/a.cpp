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

int arr[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
    string w;
    cin >> w;
    cout << arr[w[0]-'0']*arr[w[1]-'0'] << "\n";

    return 0;
}
