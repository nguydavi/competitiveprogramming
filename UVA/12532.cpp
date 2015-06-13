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

#define MAXS 100100
int N,K;
int arr[MAXS], st[MAXS << 2];

int left(int x) { return x << 1; }
int right(int x) { return (x << 1) + 1; }

char toAns(int x) {
    if(x < 0)
        return '-';
    if(x > 0)
        return '+';
    return '0';
}

void buildST(int index, int L, int R) {
    if(L==R) {
        st[index] = arr[L] == 0 ? 0 : arr[L] < 0 ? -1 : 1;
        return;
    }
    
    buildST(left(index), L, (L+R)/2);
    buildST(right(index), (L+R)/2+1, R);

    st[index] = st[left(index)] * st[right(index)];
}

int queryST(int index, int L, int R, int a, int b) {
    if(R < a || b < L)
        return 2;
    if(a <= L && R <= b)
        return st[index];

    int r1 = queryST(left(index), L, (L+R)/2, a, b);
    int r2 = queryST(right(index), (L+R)/2+1, R, a, b);

    if(r1 == 2)
        return r2;
    if(r2 == 2)
        return r1;
    return r1*r2;
}

void updateST(int index, int L, int R, int ii, int newVal) {
    if(R < ii || ii < L)
        return;
    if(L==R && L==ii) {
        st[index] = newVal == 0 ? 0 : newVal < 0 ? -1 : 1;
        return;
    }

    updateST(left(index), L, (L+R)/2, ii, newVal);
    updateST(right(index), (L+R)/2+1, R, ii, newVal);

    st[index] = st[left(index)] * st[right(index)];
}

int main() {
    while(cin >> N >> K) {
        for(int i=1;i<=N;++i)
            cin >> arr[i];

        buildST(1, 1, N);

        while(K--) {
            char op;
            int ii, jj;
            cin >> op >> ii >> jj;

            if(op == 'P')
                cout << toAns(queryST(1, 1, N, ii, jj));
            else
                updateST(1, 1, N, ii, jj);
        }
        cout << "\n";
    } 

    return 0;
}
