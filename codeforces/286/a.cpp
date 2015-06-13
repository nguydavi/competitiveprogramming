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

string s;

bool isPalindrome(const string& s) {
    for(int i=0;i<s.size()/2;++i)
        if(s[i] != s[s.size()-1-i])
            return false;
    return true;
}

string solve() {
    string res("NA");
    for(int i=0;i<=s.size();++i)
        for(int j=0;j<26;++j) {
            char let = (char)('a'+j);
            string nxt = s.substr(0,i)+let+s.substr(i);
            if(isPalindrome(nxt))
                return nxt;
        }
    return res;
}

int main() {
    cin >> s;
    cout << solve() << "\n";
    return 0;
}
