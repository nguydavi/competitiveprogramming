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

#define MAXK 20
int K;
int arr[MAXK];
vector<vector<int> > sol;

int countBits(int x) {
    int res = 0;
    while(x) {
        x = x & (x-1);
        ++res;
    }
    return res;
}

bool isBitSet(int x, int i) {
    return ((1 << i) & x) > 0;
}

int main() {
    bool start = true;
    while(cin >> K && K) {
        if(start)
            start = false;
        else
            cout << "\n";

        for(int i=0;i<K;++i)
            cin >> arr[i];
        sol.clear();

        for(int mask=0;mask< (1 << K);++mask) {
            if(countBits(mask) == 6) {
                vector<int> oneSol;
                for(int i=0;i<K;++i) 
                    if(isBitSet(mask, i))
                        oneSol.push_back(arr[i]);
                sol.push_back(oneSol);
            }
        }
        sort(sol.begin(), sol.end());

        for(int i=0;i<sol.size();++i) {
            bool first = true;
            for(int j=0;j<6;++j) {
                if(first)
                    first = false;
                else
                    cout << " ";
                cout << sol[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
