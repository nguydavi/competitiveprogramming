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

#define MAXX 10010
int N;
int arr[MAXX];

int solve() {
    int res = 0, curSum = 0;
    for(int i=0;i<N;++i) {
        curSum = max(0, curSum + arr[i]);
        res = max(res, curSum);
    }
    return res;
}

int main() {
    while(cin >> N && N) {
        bool hasOnlyNeg = true;
        for(int i=0;i<N;++i) {
            cin >> arr[i];
            if(arr[i] >= 0)
                hasOnlyNeg = false;
        }

        int ans = solve();
        if(hasOnlyNeg || !ans)
            cout << "Losing streak." << endl;
        else
            cout << "The maximum winning streak is " << ans << "." << endl;
    } 
    return 0;
}
