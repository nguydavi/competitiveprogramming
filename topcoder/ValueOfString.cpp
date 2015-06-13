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

class ValueOfString {
public:
	int findValue(string s) {
        int ans = 0;
        for(char c : s) {
            int cnt = 0;
            for(int j=0;j<s.size();++j) {
                if(s[j] <= c)
                    ++cnt;
            }
            ans += (1+c-'a')*cnt;
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
		cout << "Testing ValueOfString (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425923497;
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
		ValueOfString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "babca";
				_expected = 35;
				_received = _obj.findValue(s); break;
			}
			case 1:
			{
				string s = "zz";
				_expected = 104;
				_received = _obj.findValue(s); break;
			}
			case 2:
			{
				string s = "y";
				_expected = 25;
				_received = _obj.findValue(s); break;
			}
			case 3:
			{
				string s = "aaabbc";
				_expected = 47;
				_received = _obj.findValue(s); break;
			}
			case 4:
			{
				string s = "topcoder";
				_expected = 558;
				_received = _obj.findValue(s); break;
			}
			case 5:
			{
				string s = "thequickbrownfoxjumpsoverthelazydog";
				_expected = 11187;
				_received = _obj.findValue(s); break;
			}
			case 6:
			{
				string s = "zyxwvutsrqponmlkjihgfedcba";
				_expected = 6201;
				_received = _obj.findValue(s); break;
			}
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
			}*/
			/*case 8:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
			}*/
			/*case 9:
			{
				string s = ;
				_expected = ;
				_received = _obj.findValue(s); break;
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
