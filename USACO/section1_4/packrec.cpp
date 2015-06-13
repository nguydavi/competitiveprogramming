/*
ID: david241
PROG: packrec
LANG: C++
*/
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

vector<pair<int, int> > rectangles;
set<pair<int, int> > result;
int minArea = 1 << 30;

int min_pair(pair<int, int> p) {
    return min(p.first, p.second);
}

int max_pair(pair<int, int> p) {
    return max(p.first, p.second);
}

int smallestRect() {
    int x = 1 << 30;
    int index = -1;
    for(int i = 0; i < 4; ++i) {
        int z = max_pair(rectangles[i]);
        if(z < x) {
            index = i;
            x = z;
        }
    }
    return index;
}

int largestRect() {
    int x = 0;
    int index = -1;
    for(int i = 0; i < 4; ++i) {
        int z = max_pair(rectangles[i]);
        if(z > x) {
            index = i;
            x = z;
        }
    }
    return index;
}

void addNewResult(int x, int y) {
//    if(x*y < minArea) {
        cout << x << " " << y << endl;
        minArea = x*y;
        result.insert(make_pair(x, y));
 //   }
}

void layout1() {
    int x = 0;
    int y = 0;
    for(int i = 0; i < 4; ++i) {
        x+= min_pair(rectangles[i]);
        y+= max_pair(rectangles[i]);
    }
    addNewResult(x, y);
}

void layout2() {
    int x = 0;
    int y = 0;
    for(int i = 0; i < 4; ++i) {
        int x = 0;
        int y = min_pair(rectangles[i]);
        int maxY = 0;
        for(int j = 0; j < 4; ++j) {
            if(j != i) {
                x+= min_pair(rectangles[j]);
                int m = max_pair(rectangles[j]);
                if(m > maxY) {
                    maxY = m;
                }
            }
        }
        int z = max_pair(rectangles[i]);
        x = max(x, z);
        y += maxY;


        addNewResult(x, y);
    }
}

void layout3() {
    int big = largestRect();
    int small = smallestRect();

    int x = max_pair(rectangles[small]) + min_pair(rectangles[big]);
    int y = min_pair(rectangles[small]) + max_pair(rectangles[big]);
    for(int i = 0; i < 4; ++i) {
        if(i != big && i != small) {
            x += min_pair(rectangles[i]);
            y += max_pair(rectangles[i]);
        }
    }

    addNewResult(x, y);
}

bool cmp_rect(const pair<int, int>& a, const pair<int, int>& b ) {
    return max_pair(a) < max_pair(b);
}

void layout4() {
    vector<pair<int, int> > sorted_rect(rectangles);
    sort(sorted_rect.begin(), sorted_rect.end(), cmp_rect);

    int x = max(max_pair(sorted_rect[0]) + max_pair(sorted_rect[1]), max_pair(sorted_rect[3]));
    int y = max(min_pair(sorted_rect[0]), min_pair(sorted_rect[1]));

    addNewResult(x, y);
}

void layout5() {
    vector<pair<int, int> > sorted_rect(rectangles);
    sort(sorted_rect.begin(), sorted_rect.end(), cmp_rect);

    if(min_pair(sorted_rect[2])+min_pair(sorted_rect[3]) - min_pair(sorted_rect[1]) >= max_pair(sorted_rect[0])) {
        int x = max(max_pair(sorted_rect[3]), min_pair(sorted_rect[2]) + max(min_pair(sorted_rect[1]), max_pair(sorted_rect[0])));
        int y = max(min_pair(sorted_rect[3]) + max_pair(sorted_rect[2]), min_pair(sorted_rect[3]) + max_pair(sorted_rect[1]) + min_pair(sorted_rect[0]));

        addNewResult(x, y) ;
    }
}

int main() {
    ofstream fout("packrec.out");
    ifstream fin("packrec.in");

    for(int i = 0; i < 4; ++i) {
        int x, y;
        fin >> x >> y;
        rectangles.push_back(make_pair(x, y));
    }

    layout1();
    layout2();
    layout3();
    //layout4();
    layout5();

    fout <<  minArea << endl;
    for(set<pair<int, int> >::iterator i = result.begin(); i != result.end(); ++i) {
        int x = (*i).first;
        int y = (*i).second;
   //     if(x*y == minArea) {
//            fout << x << " " << y << endl;
    //    }
    }
    return 0;
}
