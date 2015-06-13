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

#define MAXX 300
char type;
int R,C;
bool mat[MAXX][MAXX];
int ind;

void incIndex() {
    ++ind;
    if(ind%50 == 0)
        cout << "\n";
}

bool isOnlyX(int x, int rr, int cc, int sr, int sc) {
    for(int i=0;i<sr;++i)
        for(int j=0;j<sc;++j)
            if(mat[rr+i][cc+j] != x)
                return false;
    return true;
}

void solveBitmap(int startR, int startC, int rows, int cols) {
    if(isOnlyX(1, startR, startC, rows, cols))
        cout << 1, incIndex();
    else if(isOnlyX(0, startR, startC, rows, cols))
        cout << 0, incIndex();
    else {
        cout << "D", incIndex();

        int newRows = rows/2;
        int newCols = cols/2;
        int offsetRow = rows%2;
        int offsetCol = cols%2;

        solveBitmap(startR, startC, newRows+offsetRow, newCols+offsetCol);// top left
        if(cols > 1)
            solveBitmap(startR, startC+newCols+offsetCol, newRows+offsetRow, newCols); // top right
        if(rows > 1)
            solveBitmap(startR+newRows+offsetRow, startC, newRows, newCols+offsetCol); // bottom left
        if(rows > 1 && cols > 1)
            solveBitmap(startR+newRows+offsetRow, startC+newCols+offsetCol, newRows, newCols); // bottom right
    }
}

void fillX(int x, int rr, int cc, int sr, int sc) {
    for(int i=0;i<sr;++i)
        for(int j=0;j<sc;++j)
            mat[rr+i][cc+j] = x;
}

void solveDecompo(int startR, int startC, int rows, int cols) {
    char c;
    cin >> c;
    if(c == 'D') {
        int newRows = rows/2;
        int newCols = cols/2;
        int offsetRow = rows%2;
        int offsetCol = cols%2;

        solveDecompo(startR, startC, newRows+offsetRow, newCols+offsetCol);// top left
        if(cols > 1)
            solveDecompo(startR, startC+newCols+offsetCol, newRows+offsetRow, newCols); // top right
        if(rows > 1)
            solveDecompo(startR+newRows+offsetRow, startC, newRows, newCols+offsetCol); // bottom left
        if(rows > 1 && cols > 1)
            solveDecompo(startR+newRows+offsetRow, startC+newCols+offsetCol, newRows, newCols); // bottom right
    } else {
        int x = c - '0';
        fillX(x, startR, startC, rows, cols);
    }
}

int main() {
    while(cin >> type && type != '#') {
        cin >> R >> C;
        ind = 0;

        if(type == 'B') {
            for(int i=0;i<R;++i)
                for(int j=0;j<C;++j) {
                    char c;
                    cin >> c;
                    mat[i][j] = c - '0';
                }
            printf("D%4d%4d\n", R, C);
            solveBitmap(0, 0, R, C);
        }
        else {
            printf("B%4d%4d\n", R, C);
            solveDecompo(0, 0, R, C);

            for(int i=0;i<R;++i)
                for(int j=0;j<C;++j) {
                    cout << mat[i][j];
                    incIndex();
                }
        }
        if(ind%50!=0)
            printf("\n");
    }
    
    return 0;
}
