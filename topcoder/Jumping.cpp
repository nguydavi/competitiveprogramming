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

class Jumping {
public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		
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
		cout << "Testing Jumping (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417165153;
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
		Jumping _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 5;
				int y = 4;
				int jumpLengths[] = {2, 5};
				_expected = "Able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 1:
			{
				int x = 3;
				int y = 4;
				int jumpLengths[] = {4};
				_expected = "Not able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 2:
			{
				int x = 3;
				int y = 4;
				int jumpLengths[] = {6};
				_expected = "Not able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 3:
			{
				int x = 0;
				int y = 1;
				int jumpLengths[] = {100, 100};
				_expected = "Able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 4:
			{
				int x = 300;
				int y = 400;
				int jumpLengths[] = {500};
				_expected = "Able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 5:
			{
				int x = 11;
				int y = 12;
				int jumpLengths[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = "Able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 6:
			{
				int x = 11;
				int y = 12;
				int jumpLengths[] = {1,2,3,4,5,6,7,8,9,100};
				_expected = "Not able";
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			/*case 7:
			{
				int x = ;
				int y = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x = ;
				int y = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int x = ;
				int y = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.ableToGet(x, y, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
