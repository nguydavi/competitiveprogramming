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

class AstronomicalRecordsEasy {
public:
    int gcd(int a, int b) {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }

    void simplify(vector<int>& v) {
        int gv = v[0];
        for(int i=1;i<v.size();++i) {
            gv = gcd(gv, v[i]);
        }
        for(int i=0;i<v.size();++i) {
            v[i] /= gv;
        }
    }

    int solve(const vector<int>& a, const vector<int>& b) {
        int res = 1e9;
        for(int x : a) {
            for(int y : b) {
                set<int> s;
                for(int z : a) {
                    s.insert(z*y);
                }
                for(int z : b) {
                    s.insert(z*x);
                }
                res = min(res, (int)s.size());
            }
        }
        return res;

    }

	int minimalPlanets(vector <int> A, vector <int> B) {
        simplify(A);
        simplify(B);

        return solve(A,B);
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
		cout << "Testing AstronomicalRecordsEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1436011131;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AstronomicalRecordsEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3,4};
				int B[] = {2,3,4,5};
				_expected = 5;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,2,3,4};
				int B[] = {2,4,6,8};
				_expected = 4;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1,2,3,5,6,8,9};
				int B[] = {2,4,5,6,7,8,9};
				_expected = 9;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1,2,3,4};
				int B[] = {6,7,8,9};
				_expected = 6;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {200,500};
				int B[] = {100,200,300,400,600,700,800,900};
				_expected = 9;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1,2,3,4,5,6,7,8,9,10,11,12};
				int B[] = {6,7,8,9,10,11,12,13,14,15};
				_expected = 15;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = { 2, 5, 7, 11};
				int B[] =  { 13, 17, 19, 23};
				_expected = 7;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.minimalPlanets(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
