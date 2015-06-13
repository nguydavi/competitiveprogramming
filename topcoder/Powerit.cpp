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

const int MAXN = 1e6+10;
ll dp[MAXN];

class Powerit {
public:
    /* i**(2k-1) % m */
    ll fun(int i, int k, int m) {
        ll res = 1;
        ll cur = i;

        while(k--) {
            res = (res*cur)%m;
            cur = (cur*cur)%m;
        }
        return res%m;
    }

	int calc(int n, int k, int m) {
        memset(dp, 0, sizeof(dp));
        ll ans = 0;
        for(int i=1;i<=n;++i) {
            int divi = 2;
            while(i%divi && divi*divi <= i)
                ++divi;

            if(divi*divi <= i)
                dp[i] = (dp[i/divi]*dp[divi])%m;
            else
                dp[i] = fun(i, k, m);

            ans += dp[i];
            ans %= m;
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
		cout << "Testing Powerit (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433419508;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Powerit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int k = 1;
				int m = 107;
				_expected = 10;
				_received = _obj.calc(n, k, m); break;
			}
			case 1:
			{
				int n = 4;
				int k = 2;
				int m = 107;
				_expected = 100;
				_received = _obj.calc(n, k, m); break;
			}
			case 2:
			{
				int n = 3;
				int k = 3;
				int m = 107;
				_expected = 69;
				_received = _obj.calc(n, k, m); break;
			}
			case 3:
			{
				int n = 1;
				int k = 400;
				int m = 107;
				_expected = 1;
				_received = _obj.calc(n, k, m); break;
			}
			case 4:
			{
				int n = 10;
				int k = 2;
				int m = 10;
				_expected = 5;
				_received = _obj.calc(n, k, m); break;
			}
			case 5:
			{
				int n = 1e6;
				int k = 350;
				int m = 1e9;
				_expected = 0;
				_received = _obj.calc(n, k, m); break;
			}
			case 6:
			{
				int n = 3348;
				int k = 3;
				int m = 681318585;
				_expected = 457999371;
				_received = _obj.calc(n, k, m); break;
			}
			/*case 7:
			{
				int n = ;
				int k = ;
				int m = ;
				_expected = ;
				_received = _obj.calc(n, k, m); break;
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
