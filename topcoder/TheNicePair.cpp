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

class TheNicePair {
public:
	int solve(vector <int> A) {
        int ans = -1;
        for(int i=0;i<A.size();++i)
            for(int j=i;j<A.size();++j) {
                for(int p=2;p<1010;++p) {
                    int cnt = 0;
                    for(int k=0;i+k<=j;++k) {
                        if(A[i+k] % p == 0)
                            ++cnt;
                    }
                    int half = (j-i+1) % 2 == 0 ? (j-i+1)/2 : (j-i+1)/2 +1;
                    if(cnt >= half)
                        ans = max(ans, j-i);
                }
            }

        return ans;
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
		cout << "Testing TheNicePair (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1429977604;
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
		TheNicePair _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {5,5,5,5,5};
				_expected = 4;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,1,1,1};
				_expected = -1;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {2,3,5,7};
				_expected = 1;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {8,8,5,5,5};
				_expected = 4;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1,1000,1000,1,1000,1,999};
				_expected = 5;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {1000,1,1,1000};
				_expected = 3;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1};
				_expected = 15;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 7:
			{
				int A[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
				_expected = 50;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 8:
			{
				int A[] = {5, 47, 3, 2, 47, 47};
				_expected = 5;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 9:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
