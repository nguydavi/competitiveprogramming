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

#define MAXS 10
int mat[MAXS][MAXS];
int N;

int solve() {
    int bob[N];
    for(int i=0;i<N;++i)
        bob[i] = i;

    int res = 1 << 25;
    do {
        int sum = 0;
        for(int i=0;i<N;++i)
            sum += mat[i][bob[i]];
        
        res = min(res, sum);
    } while(next_permutation(bob, bob+N));

    return res;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> N;
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                cin >> mat[i][j];

        cout << solve() << "\n";
    }
    
    return 0;
}
