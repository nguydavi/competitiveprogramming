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

#define MAXS 20
int arr[MAXS];
int goal, N;

bool isBitSet(int n, int b) {
    return ((1 << b) & n) > 0;
}

bool solve() {
    int maxi = 1 << N;
    for(int i=0;i<maxi;++i) {
        int sum = 0;
        for(int j=0;j<N;++j)
            if(isBitSet(i, j))
                sum += arr[j];
        if(sum == goal)
            return true;
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> goal >> N;
        for(int i=0;i<N;++i)
            cin >> arr[i];

        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";

    }    
    return 0;
}
