#include <cstdio>
#include <algorithm>

using namespace std;

bool isPossible(int R, int C, int M) {
    int N = R * C;
    if(M == 0) {
        return true;
    } else if(R == 1 || C == 1) {
        return true;
    } else if(M == N - 1 || M <= N - 4) {
        int vitalSpaceHori = (C - 2) * R;
        int vitalSpaceVert = (R - 2) * C;
        int maxVitalSpace = max(vitalSpaceHori, vitalSpaceVert);

        if(M <= maxVitalSpace) {
            return true;
        } else if( (M - maxVitalSpace) % 2 == 0) {
            return true;
        }
    }
    return false;
}

void printSolution(int R, int C, int M) {
    int minesLeft = M;
    int emptyCellsLeft = R * C - M;
    int minesInLastTwoRows = M - (R * C - 2 * C);
    if(minesInLastTwoRows < 0) {
        minesInLastTwoRows = 0;
    }

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(i == R - 1 && j == C - 1) {
                printf("c");
                continue;
            } else if(minesLeft > minesInLastTwoRows) {
                printf("*");
                --minesLeft;
            } else {
                if(i == R - 2) {
                    if(minesLeft > minesInLastTwoRows / 2) {
                        printf("*");
                        --minesLeft;
                    } else {
                        printf(".");
                    }
                } else {
                    if(minesLeft > 0) {
                        printf("*");
                        --minesLeft;
                    } else {
                        printf(".");
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) { 
        int R, C, M;
        scanf(" %d", &R);
        scanf(" %d", &C);
        scanf(" %d", &M);

        printf("Case #%d:\n", t);
        bool possible = isPossible(R, C, M);
        if(!possible) {
            printf("Impossible");
        } else {
            printSolution(R, C, M);
        }
        printf("\n");
    }

    return 0;
}
