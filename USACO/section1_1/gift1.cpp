/*
ID: david241
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string names[10];
int NP;

int getPersonIndex(string name) {
    for(int i = 0; i < NP; ++i) {
        if(names[i].compare(name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    ofstream fout("gift1.out");
    ifstream fin ("gift1.in");

    fin >> NP;
    for(int i = 0; i < NP; ++i) {
        string name;
        fin >> name;
        names[i] = name;
    }
    int money[10] = {0};
    
    // fin.eof() broken, wrong use and should not be used
    string gifter;
    while(fin >> gifter) {
        int gifterMoney, receivers;
        fin >> gifterMoney >> receivers;
        
        int moneyGiven = 0;
        if(receivers) {
            moneyGiven = gifterMoney / receivers;
        }
        
        for(int j = 0; j < receivers; ++j) {
            string r;
            fin >> r;
            money[getPersonIndex(r)] += moneyGiven;
        }
        
        if(moneyGiven) {
            // cannot use modulo in case moneyGiven = 1, modulo doesn't produce
            // correct output
            money[getPersonIndex(gifter)] -= receivers * moneyGiven;
        }
    }
    
    for(int i = 0; i < NP; i++) {
        fout << names[i] << " " << money[i] << endl;
    }
    return 0;
}
