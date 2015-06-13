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

typedef long long ll;

class AliceGameEasy {
public:
    ll isPossible(ll s) {
        ll left = 0;
        ll right = (ll)1e7;
        while(left < right) {
            ll mid = (left+right)/2;
            ll ss = mid*(mid+1)/2;
            if(ss == s)
                return mid;
            else if(ss < s)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if(left*(left+1)/2 == s)
            return left;
        return -1;
    }

	long long findMinimumValue(long long x, long long y) {
        ll N = isPossible(x+y);
        if(N == -1)
            return -1;

        ll turns = 0;
        ll rest = x;
        ll curMax = N;
        while(rest > 0) {
            if(rest > curMax) {
                rest -= curMax;
                --curMax;
            } else
                rest = 0;
            ++turns;
        }
        return turns;
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
		cout << "Testing AliceGameEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417176550;
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
		AliceGameEasy _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 7LL;
				long long y = 14LL;
				_expected = 2LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 1:
			{
				long long x = 10LL;
				long long y = 0LL;
				_expected = 4LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 2:
			{
				long long x = 932599670050LL;
				long long y = 67400241741LL;
				_expected = 1047062LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 3:
			{
				long long x = 7LL;
				long long y = 13LL;
				_expected = -1LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 4:
			{
				long long x = 0LL;
				long long y = 0LL;
				_expected = 0LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 5:
			{
				long long x = 100000LL;
				long long y = 400500LL;
				_expected = 106LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 6:
			{
				long long x = 7LL;
				long long y = 21LL;
				_expected = 1LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			case 7:
			{
				long long x = ((ll)1e10 + (ll)1e5)/4;
				long long y = ((ll)1e10 + (ll)1e5)/4;
				_expected = 1LL;
				_received = _obj.findMinimumValue(x, y); break;
			}
			/*case 8:
			{
				long long x = LL;
				long long y = LL;
				_expected = LL;
				_received = _obj.findMinimumValue(x, y); break;
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
