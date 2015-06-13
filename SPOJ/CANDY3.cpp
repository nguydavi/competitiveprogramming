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

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        long long sum = 0;
        for(int i=0;i<N;++i) {
            long long v;
            cin >> v;

            sum += v;
            sum %= N;
        }

        if(sum == 0)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
