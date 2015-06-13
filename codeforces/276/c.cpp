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

typedef unsigned long long ll;
int N;

int main() {
    cin >> N;
    while(N--) {
        ll L, R;
        cin >> L >> R;

        ll sol = L;
        for(int i=0;i<64;++i) {
            ll mask = 1ULL << i;
            if(((sol|mask) <= L) || ((sol|mask) <= R))
                sol |= mask;
        }
        cout << sol << "\n";
    } 
    return 0;
}
