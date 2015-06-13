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

class Cyclemin {
public:
    string shiftByOne(const string& s) {
        string res(s.substr(1));
        res += s[0];
        return res;
    }

    string changeK(const string& s, int k) {
        int index = 0;
        string res(s);
        while(k && index < s.size()) {
            if(res[index] != 'a') {
                --k;
                res[index] = 'a';
            }
            ++index;
        }
        return res;
    }

	string bestmod(string s, int k) {
        string ans = s;
        for(int i=0;i<s.size();++i) {
            string ss(s);
            for(int j=0;j<s.size();++j) {
                ss = shiftByOne(ss);
                ans = min(ans, changeK(ss, k));
            }
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
		cout << "Testing Cyclemin (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433415604;
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
		Cyclemin _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "aba";
				int k = 1;
				_expected = "aaa";
				_received = _obj.bestmod(s, k); break;
			}
			case 1:
			{
				string s = "aba";
				int k = 0;
				_expected = "aab";
				_received = _obj.bestmod(s, k); break;
			}
			case 2:
			{
				string s = "bbb";
				int k = 2;
				_expected = "aab";
				_received = _obj.bestmod(s, k); break;
			}
			case 3:
			{
				string s = "sgsgaw";
				int k = 1;
				_expected = "aasgsg";
				_received = _obj.bestmod(s, k); break;
			}
			case 4:
			{
				string s = "abacaba";
				int k = 1;
				_expected = "aaaabac";
				_received = _obj.bestmod(s, k); break;
			}
			case 5:
			{
				string s = "isgbiao";
				int k = 2;
				_expected = "aaaisgb";
				_received = _obj.bestmod(s, k); break;
			}
			case 6:
			{
				string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
				int k = 50;
				_expected = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				_received = _obj.bestmod(s, k); break;
			}
			/*case 7:
			{
				string s = ;
				int k = ;
				_expected = ;
				_received = _obj.bestmod(s, k); break;
			}*/
			/*case 8:
			{
				string s = ;
				int k = ;
				_expected = ;
				_received = _obj.bestmod(s, k); break;
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
