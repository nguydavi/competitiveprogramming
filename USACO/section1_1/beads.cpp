/*
ID: david241
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int consecutiveFirstLetter(string str, char c) {
    int result = 0;
    while(str[result++] == c); 
    return result;
}

int main() {
    ofstream fout("beads.out");
    ifstream fin ("beads.in");

    int N;
    fin >> N;
    string necklace;
    fin >> necklace;

    int result = 0;
    if(necklace.find('r') == -1 || necklace.find('b') == -1) {
        result = necklace.size();
    } else {
        int w = consecutiveFirstLetter(necklace, 'w');
        int commonW = 0;
        char lastChar = necklace[w];      
        int currentMax = 0;
        int p = 0; // length last consecutive char
        int q = 1; // length current consecutive char

        for(int i = w + 1; i < necklace.size(); ++i) {
            if('w' == necklace[i]) {
                ++w;
                ++commonW;
            } else if(lastChar == necklace[i]) {
                ++q;
                commonW = 0;
            } else {
                if(p + q + w > currentMax) {
                    currentMax = p + q + w;
                }
                lastChar = necklace[i];
                p = q + w - commonW;
                w = commonW;
                commonW = 0;
                q = 1;
            } 
        }
        int j = 0;
        while(lastChar == necklace[j] || necklace[j] == 'w') {
            ++j;
        }
        if(p + q + w + j > currentMax) {
            currentMax = p + q + w + j;
        }

        result = currentMax;
    }

    fout << result << endl;
    return 0;
}
