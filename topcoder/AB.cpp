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

class AB {
public:
	string createString(int N, int K) {
        string res = string(N/2, 'B') + string(N-N/2, 'A');
        int cnt = 0;
        if(cnt == K)
            return res;

        for(int i=0;i<N-1;++i)
            for(int j=0;j<N-1;++j)
                if(res[j] == 'B' && res[j+1] == 'A') {
                    swap(res[j], res[j+1]);
                    if(++cnt == K)
                        return res;
                }

        return "";
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
		cout << "Testing AB (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1423163233;
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
		AB _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				_expected = "ABB";
				_received = _obj.createString(N, K); break;
			}
			case 1:
			{
				int N = 2;
				int K = 0;
				_expected = "BA";
				_received = _obj.createString(N, K); break;
			}
			case 2:
			{
				int N = 5;
				int K = 8;
				_expected = "";
				_received = _obj.createString(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 12;
				_expected = "BAABBABAAB";
				_received = _obj.createString(N, K); break;
			}
			case 4:
			{
				int N = 10;
				int K = 0;
				_expected = "BBBBBBBBBA";
				_received = _obj.createString(N, K); break;
			}
			case 5:
			{
				int N = 13;
				int K = 29;
				_expected = "AAA";
				_received = _obj.createString(N, K); break;
			}
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
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
