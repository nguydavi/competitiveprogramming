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

class TaroJiroDividing {
public:
	int getNumber(int A, int B) {
        map<int, int> m;
        while(A % 2 == 0) {
            ++m[A];
            A /= 2;
        }
        ++m[A];
        
        while(B % 2 == 0) {
            ++m[B];
            B /= 2;
        }
        ++m[B];

        int ans = 0;
        for(auto kv : m)
            if(kv.second == 2)
                ++ans;
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
		cout << "Testing TaroJiroDividing (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1424281444;
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
		TaroJiroDividing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 8;
				int B = 4;
				_expected = 3;
				_received = _obj.getNumber(A, B); break;
			}
			case 1:
			{
				int A = 4;
				int B = 7;
				_expected = 0;
				_received = _obj.getNumber(A, B); break;
			}
			case 2:
			{
				int A = 12;
				int B = 12;
				_expected = 3;
				_received = _obj.getNumber(A, B); break;
			}
			case 3:
			{
				int A = 24;
				int B = 96;
				_expected = 4;
				_received = _obj.getNumber(A, B); break;
			}
			case 4:
			{
				int A = 1000000000;
				int B = 999999999;
				_expected = 0;
				_received = _obj.getNumber(A, B); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				_expected = ;
				_received = _obj.getNumber(A, B); break;
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
