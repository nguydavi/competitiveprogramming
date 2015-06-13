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

class TheConsecutiveIntegersDivOne {
public:
	int find(vector <int> numbers, int k) {
        sort(numbers.begin(), numbers.end());
        int ans = 1e9;
        for(int i=0;i<=numbers.size()-k;++i)
            for(int j=0;j<k;++j) {
                int sol = 0;
                for(int m=0;m<k;++m)
                    sol += abs((numbers[i+j] + m-j) - numbers[i+m]);

                ans = min(ans, sol);
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
		cout << "Testing TheConsecutiveIntegersDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421427811;
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
		TheConsecutiveIntegersDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {4, 7, 47};
				int k = 2;
				_expected = 2;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 1:
			{
				int numbers[] = {1, 100};
				int k = 1;
				_expected = 0;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 2:
			{
				int numbers[] = {-96, -53, 82, -24, 6, -75};
				int k = 2;
				_expected = 20;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 3:
			{
				int numbers[] = {64, -31, -56};
				int k = 2;
				_expected = 24;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 4:
			{
				int numbers[] = {-96, -53, 82, -24, 6, -75};
				int k = 4;
				_expected = 90;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 5:
			{
				int numbers[] = {46, -27, 61, -5, -10, 76, -69};
				int k = 2;
				_expected = 4;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			/*case 6:
			{
				int numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
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
