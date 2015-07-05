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

class WolfDelaymaster {
public:
	string check(string str) {
        int index = 0;
        while(index < str.size()) {
            int count = 0;
            while(str[index] == 'w')
                ++count, ++index;
            if(!count)
                return "INVALID";

            string rem("olf");
            for(char c : rem)
                for(int i=0;i<count;++i) {
                    if(index >= str.size() || str[index] != c)
                        return "INVALID";
                    ++index;
                }
        }

        return "VALID";
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
		cout << "Testing WolfDelaymaster (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1435503136;
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
		WolfDelaymaster _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string str = "wolf";
				_expected = "VALID";
				_received = _obj.check(str); break;
			}
			case 1:
			{
				string str = "wwolfolf";
				_expected = "INVALID";
				_received = _obj.check(str); break;
			}
			case 2:
			{
				string str = "wolfwwoollffwwwooolllfffwwwwoooollllffff";
				_expected = "VALID";
				_received = _obj.check(str); break;
			}
			case 3:
			{
				string str = "flowolf";
				_expected = "INVALID";
				_received = _obj.check(str); break;
			}
			case 4:
			{
				string str = "wwwoolllfff";
				_expected = "INVALID";
				_received = _obj.check(str); break;
			}
			case 5:
			{
				string str = "wwwooolllff";
				_expected = "INVALID";
				_received = _obj.check(str); break;
			}
			case 6:
			{
				string str = "wolfwol";
				_expected = "INVALID";
				_received = _obj.check(str); break;
			}
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
