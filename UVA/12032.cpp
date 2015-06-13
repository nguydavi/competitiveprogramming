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

#define MAXX 100001
int arr[MAXX];
int N;

bool isPossible(int x) {
    int strength = x;
    for(int i=0;i<N;++i) {
        int curDiff;
        if(!i)
            curDiff = arr[i];
        else
            curDiff = arr[i] - arr[i-1];

        if(strength < curDiff)
            return false;
        if(strength == curDiff)
            --strength;

    }
    return true;
}

int solve() {
    int left = 1, right = arr[N-1];
    while(left < right) {
        int mid=(left+right)/2;
        if(isPossible(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        cin >> N;

        for(int i=0;i<N;++i)
            cin >> arr[i];

        cout << "Case " << ii << ": " << solve() << "\n";
    } 
    return 0;
}
