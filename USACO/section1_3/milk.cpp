/*
ID: david241
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("milk.out");
    ifstream fin("milk.in");

    int n, m;
    fin >> n >> m;

    pair<int, int> q[5000];
    for(int i = 0; i < m; ++i) {
        int p, a;
        fin >> p >> a;
        q[i] = make_pair(p, a);
    }
    sort(q, q + m);

    int price = 0;
    int milkLeft = n;
    for(int i = 0; i < m && milkLeft > 0; ++i) {
        if(q[i].second < milkLeft) {
            milkLeft -= q[i].second;
            price += q[i].first * q[i].second;
        } else {
            price += milkLeft * q[i].first;
            milkLeft = 0;
            break;
        }
    }

    fout << price << endl;
    return 0;
}
