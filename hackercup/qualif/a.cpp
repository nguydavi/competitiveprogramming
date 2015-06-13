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

void swapStr(string& s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        string s;
        cin >> s;

        cout << "Case #" << ii << ": ";
        string minS(s);
        for(int i=0;i<s.size();++i)
            for(int j=i+1;j<s.size();++j) {
                swapStr(s, i, j);
                if(s[0] != '0')
                    minS = min(minS, s);
                swapStr(s, j, i);
            }
        cout << minS << " ";

        string maxS(s);
        for(int i=0;i<s.size();++i)
            for(int j=i+1;j<s.size();++j) {
                swapStr(s, i, j);
                maxS = max(maxS, s);
                swapStr(s, j, i);
            }
        cout << maxS << "\n";
    }
    return 0;
}
