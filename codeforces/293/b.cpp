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

const int MAXN = 2e5+10;
map<char, int> letters;
bool vis[MAXN];

int main() {
    string s, t;
    cin >> s >> t;

    for(char c : s)
        ++letters[c];

    int yay = 0, whoops = 0;
    for(int i=0;i<t.size();++i) {
        char c = t[i];
        if(letters[c] > 0) {
            ++yay;
            vis[i] = true;
            --letters[c];
        }
    }

    for(int i=0;i<t.size();++i) {
        if(!vis[i]) {
            char c = t[i];
            if(c >= 'A' && letters[tolower(c)] > 0) {
                --letters[tolower(c)];
                ++whoops;
            } else if(letters[toupper(c)] > 0){
                --letters[toupper(c)];
                ++whoops;
            }
        }
    }
    cout << yay << " " << whoops << "\n";

    return 0;
}
