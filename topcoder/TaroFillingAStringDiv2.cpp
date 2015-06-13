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

const int MAXN = 60;

class TaroFillingAStringDiv2 {
public:
    int dp[MAXN][2];

    int solve(int index, bool wasA, string& s) {
        if(index == s.size())
            return 0;
        if(dp[index][wasA] != -1)
            return dp[index][wasA];

        int res = 1e9;
        if(s[index] == '?') {
            s[index] = 'A';
            res = min(res, solve(index+1, true, s) + (s[index-1] == s[index]));

            s[index] = 'B';
            res = min(res, solve(index+1, false, s) + (s[index-1] == s[index]));

            s[index] = '?';
        } else
            res = min(res, solve(index+1, s[index] == 'A', s) + (s[index-1] == s[index]));

        dp[index][wasA] = res;
        return res;
    }

	int getNumber(string S) {
        memset(dp, -1, sizeof(dp));
        int ans = 1e9;
        if(S[0] == '?') {
            S[0] = 'A';
            ans = min(ans, solve(1, true, S));
            S[0] = 'B';
            ans = min(ans, solve(1, false, S));
        } else
            ans = min(ans, solve(1, S[0] == 'A',  S));

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
		cout << "Testing TaroFillingAStringDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1424282030;
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
		TaroFillingAStringDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "ABAA";
				_expected = 1;
				_received = _obj.getNumber(S); break;
			}
			case 1:
			{
				string S = "??";
				_expected = 0;
				_received = _obj.getNumber(S); break;
			}
			case 2:
			{
				string S = "A?A";
				_expected = 0;
				_received = _obj.getNumber(S); break;
			}
			case 3:
			{
				string S = "A??B???AAB?A???A";
				_expected = 3;
				_received = _obj.getNumber(S); break;
			}
			case 4:
			{
				string S = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?";
				_expected = 10;
				_received = _obj.getNumber(S); break;
			}
			case 5:
			{
				string S = "??????????????????????????????????????????????????";
				_expected = 0;
				_received = _obj.getNumber(S); break;
			}
			/*case 6:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.getNumber(S); break;
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
