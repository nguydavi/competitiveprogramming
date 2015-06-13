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

#define MAXS 10000
int arr[MAXS], brr[MAXS];

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        for(int i=0;i<N;++i)
            cin >> arr[i];

        for(int i=1;i<N;++i) {
            int val = arr[i];
            int count = 0;
            for(int j=0;j<i;++j)
                if(arr[j] <= val)
                    ++count;
            brr[i] = count;
        }

        int sum = 0;
        for(int i=1;i<N;++i)
            sum += brr[i];
        cout << sum << "\n";
    } 
    return 0;
}
