/*
ID: david241
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string tobaseB(int b, int n) {
    string result;
    while(n) {
        result.append(1, n % b -'0');
        n /= b;
    }
    return string(result.rbegin(), result.rend());
}

bool isPal(string n) {
    int m = n.size();
    for(int i = 0; i < m / 2; ++i) {
        if(n[i] != n[m-1-i]) {
            return false;
        }
    }
    return true;
}

bool isDualPal(int n) {
    int p = 0;
    for(int b = 2; b <= 10; ++b) {
        if(isPal(tobaseB(b, n))) {
            ++p;
            if(p >= 2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");

    int N, S;
    fin >> N >> S;

    int q = 0;
    int st = S + 1;
    while(q < N) {
        if(isDualPal(st)) {
            ++q;
            fout << st << endl;
        }
        ++st;
    }
    return 0;
}
