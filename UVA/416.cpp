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
string seq[MAXX];
bool broken[MAXX];
string model[10] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
int Q;

bool isPossible(const string& led, int number) {
    string test(model[number]);
    for(int i=0;i<7;++i)
        if(broken[i])
            test[i] = 'N';
    return led == test;
}

bool solve(int index, int expect) {
    if(index == Q)
        return true;

    vector<int> diff;
    for(int i=0;i<7;++i)
        if(seq[index][i] == 'N' && !broken[i])
            diff.push_back(i);

    for(int i=0;i<(1<<diff.size());++i) {
        for(int j=0;j<diff.size();++j)
            if(((1<<j) & i) > 0)
                broken[diff[j]] = true;

        if(isPossible(seq[index], expect)) {
            bool res = solve(index+1, expect-1);
            if(res)
                return true;
        }

        for(int j=0;j<diff.size();++j)
            if(((1<<j) & i) > 0)
                broken[diff[j]] = false;
    }
    return false;
}

int main() {
    while(cin >> Q && Q) {
        for(int i=0;i<Q;++i)
            cin >> seq[i];
        memset(broken, false, sizeof(broken));
        
        bool res = false;
        for(int i=Q-1;i<10;++i) {
            res = solve(0, i);
            if(res)
                break;
        }
        
        if(res)
            cout << "MATCH\n";
        else
            cout << "MISMATCH\n";
    }
    return 0;
}
