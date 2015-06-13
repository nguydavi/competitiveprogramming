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

const int MAXN = 5010;
int N;
vector<pair<int, int> > arr;

int solve() {
    int curDay = 0;
    for(int i=0;i<arr.size();++i) {
        if(curDay <= arr[i].second)
            curDay = arr[i].second;
        else
            curDay = arr[i].first;
    }
    return curDay;
}

int main() {
    cin >> N;
    for(int i=0;i<N;++i) { 
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(), arr.end());
    cout << solve() << "\n";

    return 0;
}
