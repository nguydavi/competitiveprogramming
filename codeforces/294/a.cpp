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

map<char, int> pointsW, pointsB;
int main() {
    pointsB['q'] = pointsW['Q'] = 9;
    pointsB['r'] = pointsW['R'] = 5;
    pointsB['b'] = pointsW['B'] = 3;
    pointsB['n'] = pointsW['N'] = 3;
    pointsB['p'] = pointsW['P'] = 1;
    pointsB['k'] = pointsW['K'] = 0;

    string line;
    int white = 0, black = 0;
    for(int i=0;i<8;++i) {
        cin >> line;
        for(char c : line) {
            if(c != '.') {
                white += pointsW[c];
                black += pointsB[c];
            }
        }
    }

    if(white > black)
        cout << "White\n";
    else if(black > white)
        cout << "Black\n";
    else
        cout << "Draw\n";
    return 0;
}
