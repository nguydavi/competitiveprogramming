/*
ID: david241
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> dict;
char letters[10][3] = {{}, {}, {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'}};


void doSolve(vector<string>& result, const string& id, string currentName, int index) {
    if(index == id.size()) {
        if(dict.find(currentName) != dict.end()) {
            result.push_back(currentName);
        }
    } else {
        for(int i = 0; i < 3; ++i) {
            string newName(currentName);
            newName.append(1, letters[id[index] - '0'][i]);
            doSolve(result, id, newName, index + 1);
        }
    }
}

vector<string> solve(const string& id) {
    vector<string> result;
    string tmp;
    doSolve(result, id, tmp, 0);
    return result;
}

int main() {
    ifstream dictfin("dict.txt");

    string name;
    while(dictfin >> name) {
        dict.insert(name);
    }

    ofstream fout("namenum.out");
    ifstream fin("namenum.in");

    string id;
    fin >> id;

    vector<string> result = solve(id);
    if(result.empty()) {
        fout << "NONE" << endl;
    } else {
        for(int i = 0; i < result.size(); ++i) {
            fout << result[i] << endl;
        }
    }
    return 0;
}
