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

class DecipherabilityEasy {
public:
	string check(string s, string t) {
        for(int i=1;i<=s.size();++i) {
            string r = s.substr(0, i-1) + s.substr(i);
            if(r == t)
                return "Possible";
        }
        return "Impossible";
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
		cout << "Testing DecipherabilityEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423584005;
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
		DecipherabilityEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "sunuke";
				string t = "snuke";
				_expected = "Possible";
				_received = _obj.check(s, t); break;
			}
			case 1:
			{
				string s = "snuke";
				string t = "skue";
				_expected = "Impossible";
				_received = _obj.check(s, t); break;
			}
			case 2:
			{
				string s = "snuke";
				string t = "snuke";
				_expected = "Impossible";
				_received = _obj.check(s, t); break;
			}
			case 3:
			{
				string s = "snukent";
				string t = "snuke";
				_expected = "Impossible";
				_received = _obj.check(s, t); break;
			}
			case 4:
			{
				string s = "aaaaa";
				string t = "aaaa";
				_expected = "Possible";
				_received = _obj.check(s, t); break;
			}
			case 5:
			{
				string s = "aaaaa";
				string t = "aaa";
				_expected = "Impossible";
				_received = _obj.check(s, t); break;
			}
			case 6:
			{
				string s = "topcoder";
				string t = "tpcoder";
				_expected = "Possible";
				_received = _obj.check(s, t); break;
			}
			case 7:
			{
				string s = "singleroundmatch";
				string t = "singeroundmatc";
				_expected = "Impossible";
				_received = _obj.check(s, t); break;
			}
			/*case 8:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.check(s, t); break;
			}*/
			/*case 9:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.check(s, t); break;
			}*/
			/*case 10:
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
