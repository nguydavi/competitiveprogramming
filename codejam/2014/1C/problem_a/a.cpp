#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <sys/resource.h>

using namespace std;

const long MAXL = 1L << 50;

struct fract {
    int num;
    int den;
};

long gcd(long a, long b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long solve(fract f) {
    long res1 = MAXL;
    long res2 = MAXL;

    if(f.num == 1 && f.den == 1) {
        return 0;
    }

    if(f.num % 3 == 0 && f.den % 4 == 0) {
        fract t;
        t.num = f.num / 3;
        t.den = f.den / 4;
        res1 = solve(t);
    }

    if(f.den % 2 == 0) {
        fract t;
        t.num = f.num;
        t.den = f.den / 2;
        res2 = solve(t); 
    } 

    if(res1 == MAXL && res2 == MAXL) {
        return -1;
    }

    if((res1 == -1 && res2 == -1) ||
            (res1 == MAXL && res2 == -1) ||
            (res1 == -1 && res2 == MAXL)) {
        return -1;
    }
    if(res1 == -1) return res2 + 1;
    if(res2 == -1) return res1 + 1;
    return min(res1 + 1, res2 + 1);
}

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t) {
        long num, den;
        char c;
        cin >> num >> c >> den;

        fract f;
        long g = gcd(num, den);
        if(g > 1) {
            f.num = num / g;
            f.den = den / g;
        } else {
            f.num = num;
            f.den = den;
        }

        long result = 1;
        if(f.num != 1 || f.den != 1) {
            result = solve(f);
        }

        if(result == -1) {
            cout << "Case #" << t << ": impossible" << endl;
        } else {
            cout << "Case #" << t << ": " << result << endl;
        }
    }
    
    return 0;
}
