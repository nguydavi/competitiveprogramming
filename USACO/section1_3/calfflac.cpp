/*
ID: david241
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

string fullText;

bool isPal(const vector<pair<char, int> >& s, int start, int end) {
    for(int i = 0; i <= (end - start) / 2; ++i) {
        if(s[start+i].first != s[end-i].first) {
            return false;
        }
    }
    return true;
}

pair<string, int> findPal(int p, const vector<pair<char, int> >& t) {
    string str;
    int m = -1;

    for(int j = 0; j < t.size() - p + 1; ++j) {
        if(isPal(t, j, j + p - 1)) {
            m = p; 
            int startIndex = t[j].second;
            int endIndex = t[j + p - 1].second;
            str = fullText.substr(startIndex, 1 + endIndex - startIndex);
            break;
        }
    }
    return make_pair(str, m);
}

int main() {
    ofstream fout("calfflac.out");
    ifstream fin("calfflac.in");

    string line;
    while(getline(fin, line)) {
        fullText += line;
        fullText += '\n';
    }

    vector<pair<char, int> > filteredText;
    locale l;
    for(int i = 0; i < fullText.size(); ++i) {
        if(isalpha(fullText[i])) {
            filteredText.push_back(make_pair(tolower(fullText[i], l), i));
        }
    }

    pair<string, int> result;
    for(int p = min(2000, (int)filteredText.size()); p > 0; --p) {
        result = findPal(p, filteredText);
        if(result.second != -1) {
            break;
        }
    }

    fout << result.second << endl;
    fout << result.first << endl;
   
    return 0;
}
