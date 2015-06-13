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

typedef pair<int, int> pii;

class ChristmasTreeDecoration {
public:
    static const int MAXN = 100;
    int N;
    int p[MAXN];
    priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;

    int findSet(int a) {
        if(p[a] == a)
            return a;
        return p[a] = findSet(p[a]);
    }

    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

    void unionSet(int a, int b) {
        p[findSet(b)] = findSet(a);
    }

    int resolve() {
        int res = 0;
        while(!pq.empty()) {
            pair<int, pii> cur = pq.top();
            pq.pop();
            int dist = cur.first;
            int u = cur.second.first;
            int v = cur.second.second;

            if(!isSameSet(u, v)){ 
                res += dist;
                unionSet(u, v);
            }
        }
        return res;
    }

	int solve(vector <int> col, vector <int> x, vector <int> y) {
        N = col.size();
        for(int i=0;i<N;++i)
            p[i] = i;

        for(int i=0;i<x.size();++i) {
            if(col[x[i]-1] == col[y[i]-1])
                pq.push(make_pair(1, pii(x[i]-1, y[i]-1)));
            else
                pq.push(make_pair(0, pii(x[i]-1, y[i]-1)));
        }

        return resolve();
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ChristmasTreeDecoration (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1418148003;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ChristmasTreeDecoration _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4};
				int y[] = {2,3,4,1};
				_expected = 1;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int col[] = {1,1,2,2};
				int x[] = {1,2,3,4,1,2};
				int y[] = {2,3,4,1,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int col[] = {50,50,50,50};
				int x[] = {1,2,3,1,1,2};
				int y[] = {2,3,4,4,3,4};
				_expected = 3;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int col[] = {1,4,2,3};
				int x[] = {1,2,3};
				int y[] = {2,3,4};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int col[] = {1,1,1,2,2,2,3,3,3,4,4,4};
				int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1};
				int y[] = {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4};
				_expected = 5;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int col[] = {1, 1};
				int x[] = {1};
				int y[] = {2};
				_expected = 1;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int col[] = {1, 2};
				int x[] = {2};
				int y[] = {1};
				_expected = 0;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 7:
			{
				int col[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(col, col+sizeof(col)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
