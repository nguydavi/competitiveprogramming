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
const int MAXN = (int)1e6+10;

class TheKingsFactorization {
public:
    bool notPrim[MAXN];

	vector<long long> getVector(long long N, vector<long long> primes) {
        ll newN = N;
        for(int i=0;i<primes.size();++i)
            newN /= primes[i];

        vector<ll> ans(primes);
        memset(notPrim, false, sizeof(notPrim));
        for(int i=2;i*i<MAXN;++i)
            if(!notPrim[i])
                for(int j=i*i;j<MAXN;j+=i)
                    notPrim[j] = true;

        for(int i=2;i<=MAXN && newN > 1;++i)
            if(!notPrim[i])
                while(newN % i == 0) {
                    ans.push_back(i);
                    newN /= i;
                }
        // if the remainder is the last prime factor (may happen if remainder is
        // bigger than MAXN)
        if(newN > 1)
            ans.push_back(newN);
        sort(ans.begin(), ans.end());
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
		cout << "Testing TheKingsFactorization (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1419699603;
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
		TheKingsFactorization _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 12LL;
				long long primes[] = {2, 3};
				long long __expected[] = {2, 2, 3 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 1:
			{
				long long N = 7LL;
				long long primes[] = {7};
				long long __expected[] = {7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 2:
			{
				long long N = 1764LL;
				long long primes[] = {2, 3, 7};
				long long __expected[] = {2, 2, 3, 3, 7, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 3:
			{
				long long N = 49LL;
				long long primes[] = {7};
				long long __expected[] = {7, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 4:
			{
				long long N = 210LL;
				long long primes[] = {2, 5};
				long long __expected[] = {2, 3, 5, 7 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 5:
			{
				long long N = 100000LL;
				long long primes[] = {2, 2, 2, 5, 5};
				long long __expected[] = {2, 2, 2, 2, 2, 5, 5, 5, 5, 5 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 6:
			{
				long long N = 1000000000LL;
				long long primes[] = {1};
				long long __expected[] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 7:
			{
				long long N = 885909753408416474LL;
				long long primes[] = {2, 999999751LL};
				long long __expected[] = {2, 442954987LL, 999999751LL};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
			}
			case 8:
			{
				long long N = 68314849208LL;
				long long primes[] = {2,2};
				long long __expected[] = {2, 2, 2, 8539356151};
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.getVector(N, vector<long long>(primes, primes+sizeof(primes)/sizeof(long long))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
