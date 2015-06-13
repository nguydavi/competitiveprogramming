/*
ID: david241
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

    // need space for \0
    char comet[8];
    char group[8];
    fin.getline(comet, 8);
    fin.getline(group, 8);
        
    int cometNum = 1;
    for(int i = 0; i < 6 && comet[i]; ++i) {
        cometNum *= (comet[i] - 'A' + 1);
    }
        
    int groupNum = 1;
    for(int i = 0; i < 6 && group[i]; ++i) {
        groupNum *= (group[i] -'A' + 1);
    }
        
    if(groupNum % 47 == cometNum % 47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    
    return 0;
}
