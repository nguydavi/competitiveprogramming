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

const int MAXN = (int)1e6+10;
int N;
char K[MAXN];

bool isGreater(const string& a, const string& b) {
    if(a.size() != b.size())
        return a.size() > b.size();

    for(int i=0;i<a.size();++i)
        if(a[i] != b[i])
            return a[i] > b[i];
    return false;
}

void makePal(string& a) {
    int len = a.size();
    for(int i=0;i<len/2;++i)
        a[len-1-i] = a[i];
}

string solve() {
    string res(K);
    makePal(res);

    if(!isGreater(res, K)) {
        int index = (N-1)/2;

        while(res[index] == '9')
            res[index--] = '0';
        ++res[index];

        makePal(res);
    }

    if(isGreater(res, K))
        return res;
    res += '1';
    res[0] = '1';
    for(int i=1;i+1<res.size();++i)
        res[i] = '0';
    return res;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s", &K);
        N = strlen(K);
        string ans = solve();
        printf("%s\n", ans.c_str());
    }
    return 0;
}
