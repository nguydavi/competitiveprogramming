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

class MountainRanges {
	public:
	int countPeaks(vector <int> heights) {
        if(heights.size() == 1)
            return 1;

        int res = 0;
	    for(int i=0;i<heights.size();++i) {
            if(!i && heights[1] < heights[i])
                ++res;
            else if(i == heights.size() -1 && heights[i] > heights[i-1])
                ++res;
            else if(heights[i] > heights[i-1] && heights[i] > heights[i+1])
                ++res;
        }    
        return res;
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
		cout << "Testing MountainRanges (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412794813;
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
		MountainRanges _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int heights[] = {5, 6, 2, 4};
				_expected = 2;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 1:
			{
				int heights[] = {1, 1, 1, 1, 1, 1, 1};
				_expected = 0;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 2:
			{
				int heights[] = {2, 1};
				_expected = 1;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 3:
			{
				int heights[] = {2,5,3,7,2,8,1,3,1};
				_expected = 4;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 4:
			{
				int heights[] = {1};
				_expected = 1;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			case 5:
			{
				int heights[] = {1,2,3,4,4,3,2,1};
				_expected = 0;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}
			/*case 6:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int heights[] = ;
				_expected = ;
				_received = _obj.countPeaks(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
