/*
ID: david241
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int B;
int N = 300;
int digits[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string tobaseB(int n) {
    string result;
    while(n) {
        result.append(1, digits[n % B]);
        n /= B;
    }
    return string(result.rbegin(), result.rend());
}

bool isPalindrome(string n) {
    int l = n.size();
    for(int i = 0; i < l / 2; ++i) {
        if(n[i] != n[l-1-i]) {
            return false;
        }
    }
    return true;
}

vector<pair<string, string> > solve() {
    vector<pair<string, string> > result;
    for(int i = 1; i <= N; ++i) {
        string square = tobaseB(i*i);
        if(isPalindrome(square)) {
            result.push_back(make_pair(tobaseB(i), square));
        }
    }
    return result;
}

int main() {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");

    fin >> B;

    vector<pair<string, string> > result = solve();
    for(int i = 0; i < result.size(); ++i) {
        fout << result[i].first << " " << result[i].second << endl;
    }
    return 0;
}
