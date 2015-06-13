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

class NarrowPassage2Easy {
public:
    bool checkIfPoss(const vector<int>& vv, const vector<int>& size, int maxSizeSum) {
        int len = vv.size();
        for(int i=0;i<len;++i)
            for(int j=i+1;j<len;++j) {
                if(vv[i] > vv[j] && size[vv[i]] + size[vv[j]] > maxSizeSum)
                    return false;
            }
       return true; 
    }

	int count(vector <int> size, int maxSizeSum) {
        vector<int> vv;
        for(int i=0;i<size.size();++i)
            vv.push_back(i);
        sort(vv.begin(), vv.end());

        int ans = 0;
        do {
            if(checkIfPoss(vv, size, maxSizeSum))
                ++ans;
        } while(next_permutation(vv.begin(), vv.end()));

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
		cout << "Testing NarrowPassage2Easy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1415129395;
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
		NarrowPassage2Easy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 3;
				_expected = 2;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 1:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 1000;
				_expected = 6;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 2:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 4;
				_expected = 3;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 3:
			{
				int size[] = {1,1,1,1,1,1};
				int maxSizeSum = 2;
				_expected = 720;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 4:
			{
				int size[] = {2,4,6,1,3,5};
				int maxSizeSum = 8;
				_expected = 60;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 5:
			{
				int size[] = {1000};
				int maxSizeSum = 1000;
				_expected = 1;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			/*case 6:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}*/
			/*case 7:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}*/
			/*case 8:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
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
