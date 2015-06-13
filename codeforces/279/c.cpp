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

const int MAXN = (int)1e6+7;
int A, B, N;
string num;
int forward[MAXN], backward[MAXN];

int main() {
    cin >> num;
    cin >> A >> B;
    N = num.size();

    forward[0] = (num[0]-'0')%A;
    for(int i=1;i<N;++i)
        forward[i] = (10*forward[i-1]+num[i]-'0')%A;
    int backten = 1;
    backward[N-1] = (num[N-1]-'0')%B;
    for(int i=1;i<=N-1;++i) {
        backten *= 10;
        backten %= B;
        backward[N-1-i] = (backward[N-i]+backten*(num[N-1-i]-'0'))%B;
    }

    for(int i=1;i<N;++i)
        if(num[i] != '0' && forward[i-1] == 0 && backward[i] == 0) {
            cout << "YES\n" << num.substr(0, i) << "\n" << num.substr(i) << "\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}
