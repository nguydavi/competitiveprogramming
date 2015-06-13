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

const int MAXN = (int)1e5+10;
int N,L,X,Y;
bitset<1000000010> bs;
int arr[MAXN];

bool isEnough(int J, int K) {
    bool res = false;
    bs[J] = 1;
    arr[N] = J;
    for(int i=0;i<=N;++i) {
        if(arr[i] >= K && bs[arr[i]-K])
            res = true;
    }
    bs[J] = 0;
    return res;
}

int main() {
    cin >> N >> L >> X >> Y; 
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        bs[arr[i]] = 1;
    }

    bool addX = true, addY = true;
    for(int i=0;i<N;++i) {
        if(arr[i] >= X && bs[arr[i]-X])
            addX = false;
        if(arr[i] >= Y && bs[arr[i]-Y])
            addY = false;
    }

    int ans = 0;
    if(addX)
        ++ans;
    if(addY)
        ++ans;

    if(ans == 2) {
        if(isEnough(X, Y))
            cout << 1 << "\n" << X << "\n";
        else if(isEnough(Y, X))
            cout << 1 << "\n" << Y << "\n";
        else
            cout << ans << "\n" << X << " " << Y << "\n";
    }
    else if(!ans)
        cout << "0\n";
    else {
        cout << ans << "\n";
        if(addX)
            cout << X << "\n";
        else
            cout << Y << "\n";
    }

    return 0;
}
