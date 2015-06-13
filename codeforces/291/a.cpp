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

int main() {
    string s;
    cin >> s;

    for(int i=0;i<s.size();++i) {
        if(i == 0 && '9'!=s[i] && '9'-s[i] < s[i]-'0')
            cout << '9'-s[i];
        else if(i > 0 && '9'-s[i] < s[i]-'0')
            cout << '9'-s[i];
        else
            cout << s[i];
    }
    cout << "\n";
    return 0;
}
