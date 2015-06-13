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

void swapStr(string& s, int a, int b) {
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

int main() {
    string num;
    while(cin >> num) {
        int firstEven = -1;
        int lastSmallerEven = -1;
        for(int i=num.size()-1;i>=0;--i) {
            if(firstEven == -1 && (num[i]-'0')%2 == 0) {
                firstEven = i;
                lastSmallerEven = i;
            } else if((num[i]-'0')%2 == 0 && (num.back()-'0') > (num[i]-'0'))
                lastSmallerEven = i;
        }

        if(lastSmallerEven != -1) {
            swapStr(num, num.size()-1, lastSmallerEven);
            cout << num << "\n";
        } else if(firstEven != -1) {
            swapStr(num, num.size()-1, firstEven);
            cout << num << "\n";
        } else
            cout << "-1\n";
    }
    return 0;
}
