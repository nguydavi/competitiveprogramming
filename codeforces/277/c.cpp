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

int N, P;
int curPos;
string word;

int solve() {
    int mid = N/2;
    int res = 0;
    int left = -1;
    int right = -1;
    if(curPos >= mid)
        curPos = N-1-curPos;

    for(int i=0;i<mid;++i)
        if(word[i] != word[N-1-i]) {
            if(left == -1)
                left = i;
            right = i;
            int diff = abs(word[i] - word[N-1-i]);
            res += min(diff, 26-diff);
        }
    int mov = min(abs(curPos - left) + (right - left), abs(curPos - right) + (right - left));
    return res ? res+mov : 0;
}

int main() {
    cin >> N >> P;
    cin >> word; 
    curPos = P-1;
    cout << solve() << "\n";
    return 0;
}
