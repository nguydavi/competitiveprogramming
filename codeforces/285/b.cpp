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

int N;
vector<vector<string> > hist;
map<string, int> mm;

int main() {
    cin >> N;
    for(int i=0;i<N;++i) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;

        if(mm.find(oldNick) == mm.end()) {
            hist.push_back(vector<string>());
            hist.back().push_back(oldNick);
            mm[oldNick] = hist.size()-1;
        }
        hist[mm[oldNick]].push_back(newNick);
        mm[newNick] = mm[oldNick];
        mm.erase(oldNick);
    }

    cout << hist.size() << "\n";
    for(int i=0;i<hist.size();++i)
        cout << hist[i].front() << " " << hist[i].back() << "\n";
    return 0;
}
