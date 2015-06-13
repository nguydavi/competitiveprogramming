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

string X, Y;

/**
 * The answer is simply all common letters from X and Y, sorted.
 * We are asked to find a string such that a PERMUTATION of it is a subsequence
 * of X and a PERMUTATION (not necessarily the same !!) of it is a subsequence
 * of Y. 
 * For it to be a subsequence of both, each letters must be contained in X
 * and Y. 
 */
int main() {
    while(getline(cin, X) && getline(cin, Y)) {
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        
        int i = 0, j = 0;
        string ans("");
        while(i < X.size() && j < Y.size()) {
            if(X[i] == Y[j]) {
                ans += X[i];
                ++i;
                ++j;
            } else if(X[i] > Y[j])
                ++j;
            else
                ++i;
        }
        cout << ans << "\n";
    }
    return 0;
}
