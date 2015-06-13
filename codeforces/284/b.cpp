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

int N, M;
map<string, string> mm;

string getShorter(const string& a, const string& b) {
    if(a.size() <= b.size())
        return a;
    return b;
}

int main() {
    scanf("%d %d", &N, &M);
    while(M--) {
        string a, b;
        cin >> a >> b;
        string val = getShorter(a, b);
        mm[a] = val;
        mm[b] = val;
    }
    for(int i=0;i<N;++i) {
        if(i)
            printf(" ");
        string word;
        cin >> word;
        cout << mm[word];
    }
    cout << "\n";
    return 0;
}
