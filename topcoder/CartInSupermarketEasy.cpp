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

const int MAXN = 110;

class CartInSupermarketEasy {
public:
    int dp[MAXN][MAXN];

    int solve(int n, int k) {
        if(n == 0 || k == 0)
            return n;
        if(dp[n][k] != -1)
            return dp[n][k];

        int res = 1 + solve(n-1, k);
        for(int i=1;i<=n;++i)
            for(int j=0;j<k;++j)
                res = min(res, 1 + max(solve(i, j), solve(n-i, k-j-1)));

        dp[n][k] = res;
        return res;
    }

	int calc(int N, int K) {
        memset(dp, -1, sizeof(dp));
        return solve(N, K);
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
		cout << "Testing CartInSupermarketEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423584415;
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
		CartInSupermarketEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int K = 0;
				_expected = 5;
				_received = _obj.calc(N, K); break;
			}
			case 1:
			{
				int N = 5;
				int K = 2;
				_expected = 4;
				_received = _obj.calc(N, K); break;
			}
			case 2:
			{
				int N = 15;
				int K = 4;
				_expected = 6;
				_received = _obj.calc(N, K); break;
			}
			case 3:
			{
				int N = 7;
				int K = 100;
				_expected = 4;
				_received = _obj.calc(N, K); break;
			}
			case 4:
			{
				int N = 45;
				int K = 5;
				_expected = 11;
				_received = _obj.calc(N, K); break;
			}
			case 5:
			{
				int N = 100;
				int K = 100;
				_expected = 8;
				_received = _obj.calc(N, K); break;
			}
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(N, K); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(N, K); break;
			}*/
			/*case 8:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.calc(N, K); break;
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
