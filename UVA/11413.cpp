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

#define MAXX 1010
#define MAXSOL 1000000100
int arr[MAXX];
int N,M;

bool isSolPossible(int x) {
    int numContainer = 1;
    int currentContainer = 0;
    for(int i=0;i<N;++i)
        if(currentContainer + arr[i] > x)
            ++numContainer, currentContainer = arr[i];
        else
            currentContainer += arr[i];

    return numContainer <= M;
}

int solve() {
    int left = 1, right = MAXSOL;
    while(left < right) {
        int mid = (left+right)/2;
        if(isSolPossible(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    while(cin >> N >> M) {
        int maxVess = 0;
        for(int i=0;i<N;++i)
            cin >> arr[i], maxVess = max(maxVess, arr[i]);
        cout << max(maxVess, solve()) << "\n";
    }

    return 0;
}
