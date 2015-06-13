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

#define MAXX 20
set<vector<int> > sol;
int arr[MAXX];
int T,N;


void solve(int index, int sum, vector<int>& curSol) {
    if(sum == T) {
        sol.insert(curSol);
        return;
    } else if(sum > T || index >= N)
        return;

    curSol.push_back(arr[index]);
    solve(index+1, sum+arr[index], curSol);
    curSol.pop_back();
    solve(index+1, sum, curSol);
}

int main() {
    while(cin >> T >> N && T && N) {
        for(int i=0;i<N;++i)
            cin >> arr[i];
        sol.clear();

        cout << "Sums of " << T << ":\n";
        vector<int> vv;
        solve(0, 0, vv);

        if(sol.empty())
            cout << "NONE\n";
        else
            for(set<vector<int> >::reverse_iterator it=sol.rbegin(); it!=sol.rend();++it) {
                vector<int> curSol = *it;
                for(int i=0;i<curSol.size();++i)
                    cout << curSol[i] << ((i==curSol.size()-1) ? "\n":"+");
            }
    }

    return 0;
}
