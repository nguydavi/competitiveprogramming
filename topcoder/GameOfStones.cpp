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

class GameOfStones {
	public:
	int count(vector <int> stones) {
		
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
		cout << "Testing GameOfStones (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1413309616;
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
		GameOfStones _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int stones[] = {7, 15, 9, 5};
				_expected = 3;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 1:
			{
				int stones[] = {10, 16};
				_expected = -1;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 2:
			{
				int stones[] = {2, 8, 4};
				_expected = -1;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 3:
			{
				int stones[] = {17};
				_expected = 0;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			case 4:
			{
				int stones[] = {10, 15, 20, 12, 1, 20};
				_expected = -1;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}
			/*case 5:
			{
				int stones[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int stones[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int stones[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(stones, stones+sizeof(stones)/sizeof(int))); break;
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
