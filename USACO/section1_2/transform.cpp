/*
ID: david241
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;

struct matrix {
    char a[10][10];
};

bool cmp(const matrix& a, const matrix& b) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(a.a[i][j] != b.a[i][j]) {
                return false;
            }
        }
    }
    return true;
}

matrix doTransform(const short trans, matrix& a, short combi = 1) {
    matrix result;
    switch(trans) {
        case 1:
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    result.a[i][j] = a.a[N-1-j][i];
                }
            }
            break;
        case 2:
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    result.a[i][j] = a.a[N-1-i][N-1-j];
                }
            }
            break;
        case 3:
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    result.a[i][j] = a.a[j][N-1-i];
                }
            }
            break;
        case 4:
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    result.a[i][j] = a.a[i][N-1-j];
                }
            }
            break;
        case 5:
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    result.a[i][j] = a.a[i][N-1-j];
                }
            }
            result = doTransform(combi, result);
            break;
    }
    return result;
}

int main() {
    ofstream fout("transform.out");
    ifstream fin ("transform.in");

    fin >> N;

    matrix origin;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            fin >> origin.a[i][j];
        }
    }
    matrix changed;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            fin >> changed.a[i][j];
        }
    }

    // compute every transformation possible
    short result = 0;
    for(short t = 1; t < 5; ++t) {
        matrix test = doTransform(t, origin);
        if(cmp(changed, test)) {
            result = t;
            break;
        }
    }

    if(!result) {
        for(short c = 1; c <= 3; ++c) {
            matrix test = doTransform(5, origin, c);
            if(cmp(changed, test)) {
                result = 5;
                break;
            }

        }
    }
    if(!result && cmp(origin, changed)) {
        result = 6;
    }
    if(!result) {
        result = 7;
    }

    fout << result << endl;
    return 0;
}
