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

typedef pair<int, char> pic;
string home, away;
int N;
set<pic> redPlayers, yellowPlayers;

int main() {
    cin >> home >> away;
    cin >> N;
    redPlayers.clear();
    yellowPlayers.clear();

    while(N--) {
        int tim, num;
        char ah, card;
        cin >> tim >> ah >> num >> card;

        if(card == 'y') {
            if(redPlayers.find(pic(num, ah)) == redPlayers.end() && yellowPlayers.find(pic(num, ah)) != yellowPlayers.end()) {
                if(ah == 'h')
                    cout << home << " " << num << " " << tim << "\n";
                else
                    cout << away << " " << num << " " << tim << "\n";
                redPlayers.insert(pic(num, ah));
                yellowPlayers.erase(yellowPlayers.find(pic(num, ah)));
            } else
                yellowPlayers.insert(pic(num, ah));
        } else {
            if(redPlayers.find(pic(num, ah)) == redPlayers.end()) {
                if(ah == 'h')
                    cout << home << " " << num << " " << tim << "\n";
                else
                    cout << away << " " << num << " " << tim << "\n";
                redPlayers.insert(pic(num, ah));
            }
        }
    }
    return 0;
}
