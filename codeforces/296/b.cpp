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

typedef pair<char, char> pcc;
const int MAXN = 2e5+10;
int N;
string S, T;
bool diff[MAXN];

int hamDist(const string& s, const string& t) {
    int res = 0;
    for(int i=0;i<N;++i)
        if(s[i] != t[i])
            ++res;
    return res;
}

int main() {
    cin >> N >> S >> T;
    int ans = hamDist(S, T);
    for(int i=0;i<N;++i)
        diff[i] = S[i] != T[i];

    map<pcc, int> mm;
    map<char, int> wrong;
    for(int i=0;i<N;++i)
        if(diff[i]) {
            wrong[S[i]] = i+1;
            mm[{S[i], T[i]}] = i+1;
        }

    bool minusOne = false;
    bool minusTwo = false;
    int index1 = -1, index2 = -1;
    for(int i=0;i<N;++i)
        if(diff[i]) {
            if(mm.find({T[i], S[i]}) != mm.end()) {
                minusTwo = true;
                minusOne = true;
                index1 = i+1;
                index2 = mm[{T[i], S[i]}];
                break;
            }

            if(wrong.find(T[i]) != wrong.end()) {
                minusOne = true;
                index1 = i+1;
                index2 = wrong[T[i]];
            }
        }

    cout << ans - minusOne - minusTwo << endl;
    cout << index1 << " " << index2 << endl;

    return 0;
}
