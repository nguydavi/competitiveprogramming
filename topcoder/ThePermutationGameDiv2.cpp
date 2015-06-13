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

class ThePermutationGameDiv2 {
public:
    ll gcd(ll a, ll b) {
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }

    ll lcm(ll a, ll b) {
        return (a*b)/gcd(a, b);
    }

	long long findMin(int N) {
        ll ans = 1;
        for(int i=2;i<=N;++i)
            ans = lcm(i, ans);
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
		cout << "Testing ThePermutationGameDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425923781;
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
		ThePermutationGameDiv2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				_expected = 2LL;
				_received = _obj.findMin(N); break;
			}
			case 1:
			{
				int N = 3;
				_expected = 6LL;
				_received = _obj.findMin(N); break;
			}
			case 2:
			{
				int N = 6;
				_expected = 60LL;
				_received = _obj.findMin(N); break;
			}
			case 3:
			{
				int N = 11;
				_expected = 27720LL;
				_received = _obj.findMin(N); break;
			}
			case 4:
			{
				int N = 25;
				_expected = 26771144400LL;
				_received = _obj.findMin(N); break;
			}
			/*case 5:
			{
				int N = ;
				_expected = LL;
				_received = _obj.findMin(N); break;
			}*/
			/*case 6:
			{
				int N = ;
				_expected = LL;
				_received = _obj.findMin(N); break;
			}*/
			/*case 7:
			{
				int N = ;
				_expected = LL;
				_received = _obj.findMin(N); break;
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
