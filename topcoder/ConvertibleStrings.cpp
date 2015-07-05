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

typedef pair<char, char> pcc;

const int MAXN = 20;
set<char> sA[MAXN], sB[MAXN];
char p[MAXN];

class ConvertibleStrings {
public:
	int leastRemovals(string A, string B) {
        int ans = A.size();
        string perm = "ABCDEFGHI";
        do {
            int sol = 0;
            for(int i=0;i<A.size();++i) {
                if(B[i] != perm[A[i]-'A'])
                    ++sol;
            }
            ans = min(ans, sol);
        } while(next_permutation(perm.begin(), perm.end()));

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
		cout << "Testing ConvertibleStrings (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1434269774;
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
		ConvertibleStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "DD";
				string B = "FF";
				_expected = 0;
				_received = _obj.leastRemovals(A, B); break;
			}
			case 1:
			{
				string A = "AAAA";
				string B = "ABCD";
				_expected = 3;
				_received = _obj.leastRemovals(A, B); break;
			}
			case 2:
			{
				string A = "AAIAIA";
				string B = "BCDBEE";
				_expected = 3;
				_received = _obj.leastRemovals(A, B); break;
			}
			case 3:
			{
				string A = "ABACDCECDCDAAABBFBEHBDFDDHHD";
				string B = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
				_expected = 9;
				_received = _obj.leastRemovals(A, B); break;
			}
			case 4:
			{
				string A = "FHI";
				string B = "III";
				_expected = 2;
				_received = _obj.leastRemovals(A, B); break;
			}
			case 5:
			{
				string A = "AFHIHFBDIHEFIFDBEFIA";
				string B = "FGFEFAFDCCACDBIFHEIF";
				_expected = 13;
				_received = _obj.leastRemovals(A, B); break;
			}
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.leastRemovals(A, B); break;
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
