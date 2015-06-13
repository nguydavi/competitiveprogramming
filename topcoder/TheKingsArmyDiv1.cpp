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

class TheKingsArmyDiv1 {
public:
	int getNumber(vector <string> state) {
		
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
		cout << "Testing TheKingsArmyDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1419700973;
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
		TheKingsArmyDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string state[] = {"HSH", 
				                  "SHS"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 1:
			{
				string state[] = {"HH", 
				                  "HH"};
				_expected = 0;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 2:
			{
				string state[] = {"HHHHH", 
				                  "HSHSH"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 3:
			{
				string state[] = {"S", 
				                  "S"};
				_expected = -1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 4:
			{
				string state[] = {"HSHHSHSHSHHHSHSHSH", 
				                  "SSSSHSSHSHSHHSSSSH"};
				_expected = 8;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 5:
			{
				string state[] = {"HS",
				                  "HS"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			/*case 6:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
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
