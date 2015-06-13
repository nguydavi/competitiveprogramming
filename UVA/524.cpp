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

#define MAXX 35
bool isPrime[MAXX];
int N;

void solve(vector<int>& curSol, set<int>& remain) {
    if(remain.empty()) {
        for(int i=0;i<curSol.size();++i)
            cout << curSol[i] << ((i==curSol.size()-1) ? "\n" : " ");
        return;
    }

    set<int> left(remain);
    for(set<int>::iterator it=left.begin();it!=left.end();++it)
        if(isPrime[*it+curSol.back()]) {
            if(curSol.size() == N-1 && !isPrime[curSol[0] + *it])
                break;

            int val = *it;
            curSol.push_back(val);
            remain.erase(val);

            solve(curSol, remain);

            curSol.pop_back();
            remain.insert(val);
        }
}

int main() {
    memset(isPrime, false, sizeof(isPrime));
    isPrime[2] = true;
    isPrime[3] = true;
    isPrime[5] = true;
    isPrime[7] = true;
    isPrime[11] = true;
    isPrime[13] = true;
    isPrime[17] = true;
    isPrime[19] = true;
    isPrime[23] = true;
    isPrime[29] = true;
    isPrime[31] = true;

    int tc = 1;
    while(cin >> N) {
        if(tc > 1)
            cout << "\n";

        set<int> ss;
        for(int i=2;i<=N;++i)
            ss.insert(i);

        cout << "Case " << tc++ << ":\n";
        vector<int> vv;
        vv.push_back(1);
        solve(vv, ss);
    }
    return 0;
}
