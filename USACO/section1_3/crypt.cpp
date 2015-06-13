/*
ID: david241
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int subset[9] = {0};

bool isInSubSet(int a, int maxDigits) {
    while(a) {
        if(!maxDigits || !subset[(a%10) - 1]) {
            return false;
        }
        a/=10;
        --maxDigits;
    }
    return true;
}

int main() {
    ofstream fout("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        subset[x-1] = 1;
    }

    int result = 0;
    for(int i = 111; i <= 909; ++i) {
        for(int j = 11; j <= 99; ++j) {
            if(!isInSubSet(i, 3) || !isInSubSet(j,2)) {
                continue;
            }

            if(isInSubSet(i * (j%10), 3) && isInSubSet(i * (j / 10), 3) && isInSubSet(i*j, 4)) {
                ++result;
            }
            
        } 
    }

    fout << result << endl;
    return 0;
}
