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

#define MAXX 1000100
vector<int> sol;
vector<vector<int> > indexChar(256);
string alph;
int Q;

int firstGreater(char c, int ii) {
    if(ii >= indexChar[c][indexChar[c].size()-1])
        return -1;

    int left = 0, right = indexChar[c].size()-1;
    while(left < right) {
        int mid = (left+right)/2;
        if(indexChar[c][mid] <= ii)
            left = mid + 1;
        else
            right = mid;
    }
    return indexChar[c][left];
}

bool solve(const string& ss) {
    int start = -1;
    for(int i=0;i<ss.size();++i) {
        start = firstGreater(ss[i], start);
        if(start == -1)
            return false;
        /*
        vector<int>::iterator it = upper_bound(indexChar[ss[i]].begin(), indexChar[ss[i]].end(), start);
        if(it == indexChar[ss[i]].end())
            return false;
        start = *it;
        */

        if(i==0)
            sol.push_back(start);
        if(i==ss.size()-1)
            sol.push_back(start);
    }
    return true;
}

int main() {
    cin >> alph;
    for(int i=0;i<alph.size();++i)
        indexChar[alph[i]].push_back(i);

    cin >> Q;
    while(Q--) {
        string query;
        cin >> query;
        sol.clear();

        if(solve(query))
            cout << "Matched " << sol[0] << " " << sol[1] << "\n";
        else
            cout << "Not matched\n";
    }
    return 0;
}
