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

string word;
int N, M, D, K;

void solve() {
    string res;
    for(int i=0;i<=N-K;++i) {
        for(int j=0;j<D;++j) {
            int index = i+j;
            while(index < i+K) {
                res += word[index];
                index += D;
            }
        }
        res += word.substr(i+K, N);
        //cout << res << endl;
        word = res;
        res = word.substr(0, i+1);
    }
    cout << word << "\n";
}

int main() {
    cin >> word;    
    N = word.size();
    cin >> M;
    for(int i=0;i<M;++i) {
        cin >> K >> D;
        solve();
    }

    return 0;
}
