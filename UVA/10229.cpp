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

typedef long long ll;
int N, M, MOD;
class matrix {
private:
    vector<vector<ll> > mat;

public:
    int row;
    int col;

    matrix(int row, int col): row(row), col(col) {
        mat = vector<vector<ll> >(row);
        for(int i=0;i<row;++i)
            mat[i] = vector<ll>(col, 0);
    }

    matrix mult(const matrix& b) {
        matrix res(row, b.col);
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j)
                for(int k=0;k<b.col;++k)
                    res.set(i, k, (res.get(i, k)%MOD + (get(i,j) * b.get(j,k))%MOD)%MOD);
                    //res.set(i, k, (res.get(i, k) + (get(i,j) * b.get(j,k))));
        return res;
    }

    matrix pow(int exp) {
        if(exp == 0) {
            matrix res(row, col);
            for(int i=0;i<row;++i)//assuming square matrix
                res.set(i,i,1);
            return res;
        }
        if(exp % 2 == 0) {
            matrix ha = pow(exp/2);
            return ha.mult(ha);
        }

        matrix re = pow(exp-1);
        return (*this).mult(re);
    }

    ll get(int r, int c) const { return mat[r][c]; }
    void set(int r, int c, ll v) { mat[r][c] = v; }
    void operator=(const matrix& b) { mat = vector<vector<ll> >(b.mat); }
};

int pow(int exp) {
    if(exp == 0)
        return 1;
    if(exp%2==0) {
        int r = pow(exp/2);
        return r*r;
    }
    int r = pow(exp-1);
    return 2*r;
}

main() {
    while(scanf("%d %d", &N, &M) == 2) {
        if(N == 0) {
            printf("0\n");
            continue;
        }

        MOD = pow(M);
        matrix a(2,2);
        a.set(0,0,1);
        a.set(0,1,1);
        a.set(1,0,1);
        a.set(1,1,0);
        a = a.pow(N-1);

        matrix fib(2,1);
        fib.set(0,0,1);
        fib.set(1,0,0);
        matrix ans = a.mult(fib);

        printf("%lld\n", ans.get(0,0));
    }
    return 0;
}
