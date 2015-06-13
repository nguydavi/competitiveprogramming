/*
ID: david241
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

// when 2 farmer start milking a cow at the same time, the farmer that start milking has priority
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return b.second < a.second;
    return a.first < b.first;
}

int main() {
    ofstream fout("milk2.out");
    ifstream fin ("milk2.in");
    
    int n;
    fin >> n;
    
    pair<int, int> t[10000];
    for(int i = 0; 2 * i < 2 *  n; ++i) {
        int start, end;
        fin >> start >> end;
        
        pair<int, int> p(start, 1);
        pair<int, int> q(end, 0);
        t[2 * i] = p;
        t[2 * i + 1] = q;
    }
    sort(t, t + 2 * n, cmp);

    int cows = 0;
    int startCowTime = -1;
    int startNoCowTime = -1;
    int maxCowTime = 0;
    int maxNoCowTime = 0;
    
    for(int i = 0; i < 2 * n; ++i) {
        if(t[i].second) {
            if(!cows) {
                startCowTime = t[i].first;
                if(startNoCowTime != -1 && t[i].first - startNoCowTime > maxNoCowTime) {
                    maxNoCowTime = t[i].first - startNoCowTime;
                }
            }
            ++cows;
        } else {
            --cows;
            if(!cows) {
                startNoCowTime = t[i].first;
                if(startCowTime != -1 && t[i].first - startCowTime > maxCowTime) {
                    maxCowTime = t[i].first - startCowTime;
                }
            }
        }
    }
    
    fout << maxCowTime << " " << maxNoCowTime << endl;
    return 0;
}
