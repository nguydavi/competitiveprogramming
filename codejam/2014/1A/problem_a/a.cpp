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

vector<string> outlets;
vector<string> devices;
int N, L;

bool isPossible(const vector<string>& a, const vector<string>& b) {
    /*for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << ", ";
    }
    cout << endl;
    for(int i = 0; i < b.size(); ++i) {
        cout << b[i] << ", ";
    }
    cout << endl;*/
    vector<string> copy(a);
    for(int i = 0; i < b.size(); ++i) {
        vector<string>::iterator it = find(copy.begin(), copy.end(), b[i]);
        if(it != copy.end()) {
            copy.erase(it);
        }
    }
    /*for(int i = 0; i < copy.size(); ++i) {
        cout << copy[i] << ", ";
    }
    cout << endl;
    cout << endl;*/
    return copy.empty();
}

string switchBit(string a, int index) {
    string result(a);
    if(a[index] == '1') result[index] = '0';
    else result[index] = '1';

    return result;
}

vector<string> turnSwitch(int a) {
    vector<string> result(outlets);
    for(int i = 0; i < 10; ++i) {
        int mask = 1 << i;
        if(a & mask) {
            for(int j = 0; j < result.size(); ++j) {
                result[j] = switchBit(result[j], i);
            }
        }
    }

    return result;
}

int countSwitches(int a) {
    int result = 0;
    while(a) {
        ++result;
        a = a & (a-1);
    }
    return result;
}

int solve() {
    int minResult = 50;
    for(int i=0; i < (1<<L) ; ++i) {
        if(isPossible(turnSwitch(i), devices)) {
            int count = countSwitches(i);
            if(count < minResult) {
                minResult = count;
            }
        }
    }
    if(minResult == 50) minResult = -1;
    return minResult;
}

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t) {
        cin >> N >> L;

        outlets.clear();
        for(int i = 0; i < N; ++i) {
            string outlet;
            cin >> outlet;

            outlets.push_back(outlet);
        }

        devices.clear();
        for(int i = 0; i < N; ++i) {
            string device;
            cin >> device;

            devices.push_back(device);
        }

        int minSwitch = solve();

        if(minSwitch == -1) {
            cout << "Case #" << t << ": NOT POSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << minSwitch << endl;
        }
    }
    
    return 0;
}
