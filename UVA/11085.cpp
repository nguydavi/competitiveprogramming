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

#define MAXX 8
set<vector<int> > sol;
int target[MAXX];

bool isAttacked(const vector<int>& curSol, int qq) {
    if(!curSol.size())
        return false;

    int row = qq;
    int col = curSol.size();

    for(int i=0;i<curSol.size();++i)
        if(row == curSol[i] || abs(col-i) == abs(row-curSol[i]))
            return true;
    return false;

}

void precompute(vector<int> curSol) {
    if(curSol.size() == MAXX) {
        sol.insert(curSol);
        return;
    }


    for(int i=1;i<=MAXX;++i)
        if(!isAttacked(curSol, i))
            curSol.push_back(i), precompute(curSol), curSol.pop_back();
}

int calcDist(const vector<int>& poss) {
    int res = 0;
    for(int i=0;i<MAXX;++i)
        if(target[i] != poss[i])
            ++res;
    return res;
}

int main() {
    precompute(vector<int>());

    int tc = 1;
    while(cin >> target[0]) {
        for(int i=1;i<MAXX;++i)
            cin >> target[i];

        int minDist = 1<<25;
        for(set<vector<int> >::iterator it=sol.begin();it!=sol.end();++it)
            minDist = min(minDist, calcDist(*it));

        cout << "Case " << tc++ << ": " << minDist << "\n";
    }

    return 0;
}
