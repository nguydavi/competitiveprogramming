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

class DifferentStrings {
public:
	int minimize(string A, string B) {
		
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
		cout << "Testing DifferentStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417165171;
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
		DifferentStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "koder";
				string B = "topcoder";
				_expected = 1;
				_received = _obj.minimize(A, B); break;
			}
			case 1:
			{
				string A = "hello";
				string B = "xello";
				_expected = 1;
				_received = _obj.minimize(A, B); break;
			}
			case 2:
			{
				string A = "abc";
				string B = "topabcoder";
				_expected = 0;
				_received = _obj.minimize(A, B); break;
			}
			case 3:
			{
				string A = "adaabc";
				string B = "aababbc";
				_expected = 2;
				_received = _obj.minimize(A, B); break;
			}
			case 4:
			{
				string A = "giorgi";
				string B = "igroig";
				_expected = 6;
				_received = _obj.minimize(A, B); break;
			}
			/*case 5:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimize(A, B); break;
			}*/
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimize(A, B); break;
			}*/
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimize(A, B); break;
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
