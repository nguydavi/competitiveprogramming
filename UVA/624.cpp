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

#define MAXX 20
int N, T;
int arr[MAXX];

pair<int, int> solve() {
    int maxi = 1 << T;
    int maxSum = 0, maxCombi;
    for(int i=0;i<maxi;++i) {
        int sum = 0;
        for(int j=0;j<T;++j)
            if((1<<j) & i)
                sum += arr[j];
        if(sum <= N && maxSum < sum)
            maxSum = sum, maxCombi = i;
    }
    return make_pair(maxCombi, maxSum);
}

int main() {
    while(cin >> N) {
        cin >> T;
        for(int i=0;i<T;++i)
            cin >> arr[i];

        pair<int, int> sol = solve();
        for(int i=0;i<T;++i)
            if((1<<i) & sol.first)
                cout << arr[i] << " ";
        cout << "sum:" << sol.second << "\n";
    }
    return 0;
}
