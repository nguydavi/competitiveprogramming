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

const int INF = 1e9;
const int MAXN = 1e5+10;

class BuildingTowersEasy {
public:
	int maxHeight(int N, vector <int> x, vector <int> t) {
        int heights[MAXN];
        for(int i=0;i<N;++i)
            heights[i] = i;

        for(int i=0;i<x.size();++i) {
            for(int j=0;x[i]-1-j >= 0; ++j)
                heights[x[i]-1-j] = min(heights[x[i]-1-j], t[i]+j);
            for(int j=0;x[i]-1+j < N;++j)
                heights[x[i]-1+j] = min(heights[x[i]-1+j], t[i]+j);
        }

        int ans = 0;
        for(int i=0;i<N;++i)
            ans = max(ans, heights[i]);

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
		cout << "Testing BuildingTowersEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1422118803;
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
		BuildingTowersEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int x[] = {3,8};
				int t[] = {1,1};
				_expected = 3;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 100000;
				int x[] = {};
				int t[] = {};
				_expected = 99999;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 2718;
				int x[] = {1,30,400,1300,2500};
				int t[] = {100000,100000,100000,100000,100000};
				_expected = 2717;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 20;
				int x[] = {4,7,13,15,18};
				int t[] = {3,8,1,17,16};
				_expected = 8;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 447;
				int x[] = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435};
				int t[] = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14};
				_expected = 120;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 97638;
				int x[] = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,
				          25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,
				          61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,
				          86277,88611,92793,93214,97583};
				int t[] = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,
				          433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,
				          83,390,14,38441,16021,4,39386};
				_expected = 6343;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int x[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int x[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int x[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.maxHeight(N, vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
