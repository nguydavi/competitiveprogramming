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

class FoxAndSouvenirTheNext {
public:
    int dp[1500][30][60];
    bool solve(int sum, int left,int index, const vector<int> v) {
        if(sum < 0 || index == v.size())
            return false;
        if(left == 0)
            return sum == 0;
        if(dp[sum][left][index] != -1)
            return dp[sum][left][index];

        bool res = solve(sum, left, index+1, v);
        res = res || solve(sum-v[index], left-1, index+1, v);
        dp[sum][left][index] = res;
        return res;
    }

	string ableToSplit(vector <int> value) {
        if(value.size()%2 == 1)
            return "Impossible";
        int total = 0;
        for(int v : value)
            total += v;
        if(total %2 == 1)
            return "Impossible";

        memset(dp, -1, sizeof(dp));
        if(solve(total/2, value.size()/2, 0, value))
            return "Possible";
        return "Impossible";
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
		cout << "Testing FoxAndSouvenirTheNext (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425143394;
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
		FoxAndSouvenirTheNext _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int value[] = {1,2,3,4};
				_expected = "Possible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 1:
			{
				int value[] = {1,1,1,3};
				_expected = "Impossible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 2:
			{
				int value[] = {1,1,2,3,5,8};
				_expected = "Possible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 3:
			{
				int value[] = {2,3,5,7,11,13};
				_expected = "Impossible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 4:
			{
				int value[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
				_expected = "Possible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 5:
			{
				int value[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
				_expected = "Impossible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 6:
			{
				int value[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
				_expected = "Possible";
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			/*case 7:
			{
				int value[] = ;
				_expected = ;
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int value[] = ;
				_expected = ;
				_received = _obj.ableToSplit(vector <int>(value, value+sizeof(value)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
