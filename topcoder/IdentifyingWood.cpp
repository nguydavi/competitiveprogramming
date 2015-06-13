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

class IdentifyingWood {
	public:
	string check(string s, string t) {
        int index1 = 0, index2 = 0;
        while(index1 < s.size() && index2 < t.size()) {
            if(s[index1] == t[index2])
                ++index2;
            ++index1;
        }
        if(index2 == t.size())
            return "Yep, it's wood.";
        return "Nope.";
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
		cout << "Testing IdentifyingWood (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412794477;
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
		IdentifyingWood _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "absdefgh";
				string t = "asdf";
				_expected = "Yep, it's wood.";
				_received = _obj.check(s, t); break;
			}
			case 1:
			{
				string s = "oxoxoxox";
				string t = "ooxxoo";
				_expected = "Nope.";
				_received = _obj.check(s, t); break;
			}
			case 2:
			{
				string s = "oxoxoxox";
				string t = "xxx";
				_expected = "Yep, it's wood.";
				_received = _obj.check(s, t); break;
			}
			case 3:
			{
				string s = "qwerty";
				string t = "qwerty";
				_expected = "Yep, it's wood.";
				_received = _obj.check(s, t); break;
			}
			case 4:
			{
				string s = "string";
				string t = "longstring";
				_expected = "Nope.";
				_received = _obj.check(s, t); break;
			}
			/*case 5:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.check(s, t); break;
			}*/
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.check(s, t); break;
			}*/
			/*case 7:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.check(s, t); break;
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
