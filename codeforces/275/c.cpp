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

int N, K;
int main() {
    cin >> N >> K; 
    if(K == 1) {
        cout << 1;
        for(int i=2;i<=N;++i)
            cout << " " << i;
    } else {
        int cur = K+1;
        int diff = K;
        cout << cur;
        while(diff) {
            cout << " ";
            if(cur > K/2)
                cur -= diff;
            else
                cur += diff;
            --diff;
            cout << cur;
        }


        for(int i=K+2;i<=N;++i)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}
