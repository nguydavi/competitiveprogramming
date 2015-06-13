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

#define MAXS 1025000

enum State {
    Flip, Set, Clear, None
};

bitset<MAXS> land;
pair<int, State> st[MAXS << 2];
int maxIndex;


int left(int x) { return x << 1; }
int right(int x) { return (x << 1) +1; }

State nextState(State oldState, State newState) {
    if(oldState == Flip && newState == Flip)
        return None;
    else if(oldState == Set && newState == Flip)
        return Clear;
    else if(oldState == Clear && newState == Flip)
        return Set;
    else if(newState == None)
        return oldState;
    
    return newState;
}

int getBitCount(State s, int oldVal, int L, int R) {
    if(s == Set)
        return R-L+1;
    else if(s == Flip)
        return R-L+1-oldVal;
    else if(s == Clear)
        return 0;
    return oldVal;
}

void propState(int index, State state) {
    st[left(index)].second = nextState(st[left(index)].second, state);
    st[right(index)].second = nextState(st[right(index)].second, state);
}

void propagate(int index, int L, int R) {
    State state = st[index].second;
    st[left(index)].second = nextState(st[left(index)].second, state);
    st[right(index)].second = nextState(st[right(index)].second, state);

    //cout << "BEFORE LEFT " << st[left(index)].second << " RIGHT " << st[right(index)].second << endl;
    st[left(index)].first = getBitCount(st[left(index)].second, st[left(index)].first, L, (L+R)/2);
    st[right(index)].first = getBitCount(st[right(index)].second, st[right(index)].first, (L+R)/2+1, R);

    if(L != (L+R)/2)
        propState(left(index), st[left(index)].second);
    if((L+R)/2+1 != R)
        propState(right(index), st[right(index)].second);

    st[left(index)].second = None;
    st[right(index)].second = None;

    //cout << "LEFT " << st[left(index)].first << " RIGHT " << st[right(index)].first << endl;
}

void buildST(int index, int L, int R) {
    if(L==R) {
        st[index] = make_pair(land[L], None);
        return;
    }
    
    buildST(left(index), L, (L+R)/2);
    buildST(right(index), (L+R)/2+1, R);
    
    st[index] = make_pair(st[left(index)].first + st[right(index)].first, None);
}

int rsq(int index, int L, int R, int a, int b) {
    if(R < a || b < L)
        return -1;

    if(L!=R)    
        propagate(index, L, R);

    if(a <= L && R <= b)
        return st[index].first;
        
    int r1 = rsq(left(index), L, (L+R)/2, a ,b);
    int r2 = rsq(right(index), (L+R)/2+1, R, a, b);
    
    if(r1 == -1)
        return r2;
    if(r2 == -1)
        return r1;
    
    return r1+r2;
}

void updateST(int index, int L, int R, int a, int b, State state) {
    if(R < a || b < L)
        return;
    
    if(L!=R)    
        propagate(index, L, R);
    
    if(a <= L && R <= b) {
        State prev = st[index].second;
        if(prev != Flip || state != Flip)
            st[index] = make_pair(getBitCount(state, st[index].first, L, R), None);
        else
            st[index].second = None;

        st[left(index)].second = nextState(st[left(index)].second, state);
        st[right(index)].second = nextState(st[right(index)].second, state);
        //cout << L << ":" << R << " " << st[index].first << ", LEFT=" << st[left(index)].second << endl;
        return;
    }
    
    //cout << L << ":" << R << " " << st[index].first << endl;
    updateST(left(index), L, (L+R)/2, a, b, state);
    updateST(right(index), (L+R)/2+1, R, a, b, state);
    
    st[index] = make_pair(st[left(index)].first + st[right(index)].first, None);
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        int M;
        cin >> M;
        
        maxIndex = 1;
        while(M--) {
            int T;
            string pir;
            cin >> T >> pir;
            
            while(T--) {
                for(int i=0;i<pir.size();++i)
                    land[maxIndex++] = pir[i] - '0';
            }
        }
        --maxIndex;
        buildST(1, 1, maxIndex);
        
        int Q, queryNum = 1;
        cin >> Q;
        cout << "Case " << ii << ":\n";
        
        while(Q--) {
            char op;
            int ii, jj;
            cin >> op >> ii >> jj;
            ++ii, ++jj;

            //cout << "NEW OP" << endl;
            if(op == 'F')
                updateST(1, 1, maxIndex, ii, jj, Set);
            else if(op == 'E')
                updateST(1, 1, maxIndex, ii, jj, Clear);
            else if(op == 'I')
                updateST(1, 1, maxIndex, ii, jj, Flip);
            else if(op == 'S') 
                cout << "Q" << queryNum++ << ": " << rsq(1, 1, maxIndex, ii, jj) << "\n";
        }
    }
    return 0;
}
