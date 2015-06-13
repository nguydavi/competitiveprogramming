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

bool hasRealSol;
int realSol, totalSol, correctSol;

void solve(const string& ss, int index, int currentSol) {
    if(index == ss.size()) {
        if(currentSol == realSol)
            hasRealSol = true, ++correctSol;
        ++totalSol;
        return;
    }

    if(ss[index] == '+')
        solve(ss, index+1, currentSol+1);
    else if(ss[index] == '-')
        solve(ss, index+1, currentSol-1);
    else {
        solve(ss, index+1, currentSol+1);
        solve(ss, index+1, currentSol-1);
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    realSol = 0;
    for(int i=0;i<s1.size();++i)
        if(s1[i] == '+')
            ++realSol;
        else
            --realSol;

    hasRealSol = false;
    solve(s2, 0, 0);

    if(hasRealSol)
        printf("%.9lf\n", 1.0*correctSol/totalSol);
    else
        printf("%.9lf\n", 0.0);
    
    return 0;
}
