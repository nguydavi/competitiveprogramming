/*
ID: david241
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");

    int m, s, c;
    fin >> m >> s >> c;

    bool stalls[200] = {false};
    for(int i = 0; i < s; ++i) {
        int id;
        fin >> id;
        stalls[id-1] = true;
    }

    int currentIntervalStart = -1;
    int lastNoBoardInterval = -1;
    vector<int> t;
    vector<int> d;
    for(int i = 0; i < s; ++i) {
        if(stalls[i] && currentIntervalStart == -1) {
            if(lastNoBoardInterval != -1) {
                d.push_back(i - lastNoBoardInterval);
            }
            currentIntervalStart = i;
            lastNoBoardInterval = -1;
        } else if(!stalls[i] && currentIntervalStart != -1) {
            t.push_back(i - currentIntervalStart); 
            currentIntervalStart = -1;
            lastNoBoardInterval = i;
        }
    }
    if(currentIntervalStart != -1) {
        t.push_back(s-currentIntervalStart);
    }
    sort(d.begin(), d.end());
    
    // calculating number of stalls covered with boards only to adjacent stalls
    int nStalls = 0;
    for(int i = 0; i < t.size(); ++i) {
        nStalls += t[i];
    }

    // joigning boards with shortest distance until we reach m
    int nboards = t.size();
    if(nboards > m) {
        int diff = nboards - m;
        for(int i = 0; i < diff; ++i) {
            nStalls += d[i];
        }
    }

    fout << nStalls << endl;
    return 0;
}
