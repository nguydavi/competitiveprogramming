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

const int MAXD = 1<<10;
class Similars {
public:
    int countBits(int x) {
        int res = 0;
        while(x) {
            ++res;
            x &= x-1;
        }
        return res;
    }

	int maxsim(int L, int R) {
        int digits[MAXD];
        memset(digits, 0, sizeof(digits));

        for(int i=L;i<=R;++i) {
            int d = 0;
            int x = i;
            while(x) {
                d |= 1<<(x%10);
                x /= 10;
            }
            ++digits[d];
        }

        int ans = 0;
        for(int i=0;i<MAXD;++i)
            for(int j=i;j<MAXD;++j)
                if((i==j && digits[i] > 1) || (i!=j && digits[i] && digits[j]))
                    ans = max(ans, countBits(i&j));
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
		cout << "Testing Similars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1428768005;
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
		Similars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 1;
				int R = 10;
				_expected = 1;
				_received = _obj.maxsim(L, R); break;
			}
			case 1:
			{
				int L = 1;
				int R = 99;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 2:
			{
				int L = 99;
				int R = 100;
				_expected = 0;
				_received = _obj.maxsim(L, R); break;
			}
			case 3:
			{
				int L = 1000;
				int R = 1010;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			case 4:
			{
				int L = 444;
				int R = 454;
				_expected = 2;
				_received = _obj.maxsim(L, R); break;
			}
			/*case 5:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
			}*/
			/*case 6:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
			}*/
			/*case 7:
			{
				int L = ;
				int R = ;
				_expected = ;
				_received = _obj.maxsim(L, R); break;
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
