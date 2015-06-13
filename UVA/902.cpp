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

int N;

int main() {
    string word;
    while(cin >> N >> word) {
        map<string, int> mm;
        string ans;
        int maxSub = 0;
        for(int i=0;i<=word.size()-N;++i) {
            string sub = word.substr(i, N);
            ++mm[sub];
            if(maxSub < mm[sub]) {
                maxSub = mm[sub];
                ans = sub;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
