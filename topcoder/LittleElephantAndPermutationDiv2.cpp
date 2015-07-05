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
const int MAXN = 20;

ll fact[MAXN];

class LittleElephantAndPermutationDiv2 {
public:
	long long getNumber(int N, int K) {
        memset(fact, 0, sizeof(fact));
        fact[0] = 1;
        for(int i=1;i<MAXN;++i)
            fact[i] = i*fact[i-1];

        vector<int> arr(N);
        for(int i=0;i<N;++i)
            arr[i] = i+1;

        ll ans = 0;
        do {
            int sum = 0;
            for(int i=1;i<=N;++i)
                sum += max(i, arr[i-1]);

            if(sum >= K)
                ++ans;

        } while(next_permutation(arr.begin(), arr.end()));

        return ans * fact[N];
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
		cout << "Testing LittleElephantAndPermutationDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1435419140;
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
		LittleElephantAndPermutationDiv2 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int K = 1;
				_expected = 1LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 1:
			{
				int N = 2;
				int K = 1;
				_expected = 4LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 2:
			{
				int N = 3;
				int K = 8;
				_expected = 18LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 47;
				_expected = 13168189440000LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 4:
			{
				int N = 10;
				int K = 5;
				_expected = 13168189440000LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 5:
			{
				int N = 7;
				int K = 47;
				_expected = 0LL;
				_received = _obj.getNumber(N, K); break;
			}
			case 6:
			{
				int N = 10;
				int K = 70;
				_expected = 9397924300800LL;
				_received = _obj.getNumber(N, K); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
