#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <cstdlib>

using namespace std;

string reducedForm;

string reduce(const string& s) {
    string result;
    char oldC = s[0];
    result.push_back(s[0]);

    for(int i = 1; i < s.size(); ++i) {
        if(s[i] != oldC) {
            result.push_back(s[i]);
            oldC = s[i];
        }
    }
    return result;
}

bool isReduceable(const vector<string>& v) {
    string reduced = reduce(v[0]);
    for(int i = 1; i < v.size(); ++i) {
        if(reduced.compare(reduce(v[i]))) {
            return false;
        }
    }
    reducedForm = reduced;
    return true;
}

int countNthChar(int nthChar, const string& s) {
    int currentChar = 0;
    char oldChar = s[0];
    int index = 0;
    for(int i = 0; i < s.size() && currentChar < nthChar; ++i) {
        if(oldChar != s[i]) {
            oldChar = s[i];
            index = i;
            ++currentChar;
        }
    }

    int result = 0;
    for(int j = index; j < s.size(); ++j) {
        if(s[j] != oldChar) {
            break;
        }
        ++result; 
    }
    return result;
}

int countOptimal(int nthChar, const vector<string>& v) {
    vector<int> occurence(101, 0);
    for(int i = 0; i < v.size(); ++i) {
        int t = countNthChar(nthChar, v[i]);
        ++occurence[t];
    }
    int result = 0;
    int maxOccur = 0;
    for(int i = 0; i <= 100; ++i) {
        if(occurence[i] > maxOccur) {
            result = i;
            maxOccur = occurence[i];
        }
    }
    return result;
}

string getIdeal(const vector<string>&  v) {
    string result;
    for(int i = 0; i < reducedForm.size(); ++i) {
        int opti = countOptimal(i, v);
        for(int j = 0; j < opti; ++j) {
            result.push_back(reducedForm[i]);
        }
    }
    return result;
}

int solve(const string& s, const vector<string>& v) {
    int result = 0;
    for(int i = 0; i < reducedForm.size(); ++i) {
        for(int j = 0; j < v.size(); ++j) {
            result += abs(countNthChar(i, s) - countNthChar(i, v[j]));
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<string> col;
        for(int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            col.push_back(s);
        }

        cout << "Case #" << t << ": ";
        if(!isReduceable(col)) {
            cout << "Fegla Won" << endl;
            continue;
        }

        string ideal(getIdeal(col));
        int result = solve(ideal, col);
        cout << result << endl;

    }
    
    return 0;
}
