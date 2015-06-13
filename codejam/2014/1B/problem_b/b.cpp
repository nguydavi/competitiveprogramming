#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string toBin(int i) {
    string result(32, '0');
    int mask = 1;
    for(int j = 0; j < 32; ++j) {
        if(i & mask) {
            result[j] = '1';
        }
        mask = mask << 1;
    }
    return result;
}

void doGenerSol(string i, string aa, string bb, int A, int B, int index, int& result) {
    if(index == i.size()) {
        if(atoi(aa.c_str()) < A && atoi(bb.c_str()) < B) {
            ++result;
        }
        return;
    }

   if(i[index] == '1') {
       doGenerSol(i, aa + "1", bb + "1", A, B, index + 1, result);
   } else {
       doGenerSol(i, aa + "0", bb + "1", A, B, index + 1, result);
       doGenerSol(i, aa + "1", bb + "0", A, B, index + 1, result);
       doGenerSol(i, aa + "0", bb + "0", A, B, index + 1, result);
   }
}

int generSol(int i, int A, int B) {
    string iBinary = toBin(i);
    int result = 0;
    doGenerSol(iBinary, string(), string(), A, B, 0, result);
    return result;
}

int solve(int A, int B, int K) {
    int result = 0;
    for(int i = 0; i < K; ++i) {
        result += generSol(i, A, B);
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t) {
        int A, B, K;
        cin >> A >> B >> K;

        int result = solve(A, B, K);
        cout << "Case #" << t << ": ";
        cout << result << endl;
    }
    
    return 0;
}
