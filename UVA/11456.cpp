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

#define MAXX 2010
int N;
int arr[MAXX];

// we are calculating lis and lds starting from i because we can put the
// following before and after i
// -> if we were to calculate lis and lds ending at i, we wouldn't be able to
// put the train before and after i
int solve() {
    vector<int> lis(N), lds(N);
    int res = 0;
    for(int i=N-1;i>=0;--i) {
        lis[i] = 1;
        lds[i] = 1;
        for(int j=N-1;j>i;--j) {
            if(arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j]+1);
            else if(arr[i] < arr[j])
                lds[i] = max(lds[i], lds[j]+1);
        }
        res = max(res, lis[i]+lds[i]-1);
    }
    return res;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N;
        for(int i=0;i<N;++i)
            cin >> arr[i];
            
        cout << solve() << "\n";
    }
    return 0;
}
