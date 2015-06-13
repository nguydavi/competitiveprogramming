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

bool lookForSum(const vector<int>& a, int sum, int numSummand) {
    if(!numSummand) {
       if(!sum) {
        return true;
       } 
       return false;
    }

    for(int i = 0; i < a.size(); ++i) {
        vector<int> copy(a);
        copy.erase(find(copy.begin(), copy.end(), a[i]));
        bool tmp = lookForSum(copy, sum - a[i], numSummand - 1);
        if(tmp) return true;
    }
    return false;
}

int computeMinResult(const vector<int>& a, int sum, int minNode) {
    bool tmp = false;
    while(!tmp) {
        tmp = lookForSum(a, sum - 2*(a.size() - minNode - 1), minNode);
        ++minNode;
    }

    return minNode;
}

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> nodes(N, 0);
        for(int j = 0; j < N-1; ++j) {
            int x, y;
            cin >> x >> y;
            ++nodes[x-1];
            ++nodes[y-1];
        }

        int sumDeg = 0;
        bool isCorrect = true;
        for(int k = 0; k < N; ++k) {
            sumDeg += nodes[k];
            if(isCorrect && nodes[k] != 1 && nodes[k] != 3) {
                isCorrect = false;
            }
        }

        int numEdges = sumDeg / 2;
        int result = 0;

        if(isCorrect && (N-1) % 2 == 0 && N - 1 == numEdges) {
            result = 0;
        } else if(N % 2 == 0) {
            result = computeMinResult(nodes, sumDeg, 2);
        } else {
            result = computeMinResult(nodes, sumDeg, 1);
        }

        cout << "Case #" << t << ": " << result << endl;
    }
    
    return 0;
}
