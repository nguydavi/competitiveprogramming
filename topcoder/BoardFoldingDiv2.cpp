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

class BoardFoldingDiv2 {
public:
    int R, C;
    vector<string> init;
    set<vector<string> > sol;

    bool canFold(int topLeftR, int topLeftC, int botRightR, int botRightC, int offsetR, int offsetC) {
    }

    vector<string> extract(int topLeftR, int topLeftC, int botRightR, int botRightC) {
        vector<string> res;
        for(int i=0;i<R;++i) {
            if(i <= botRightR && i >= topLeftR) {
                string ss;
                for(int j=0;j<C;++j) {
                    if(j <= botRightC && j >= topLeftC)
                        ss += init[i][j];
                }
                res.push_back(ss);
            }
        }
        return res;
    }

    void solve(int topLeftR, int topLeftC, int botRightR, int botRightC) {
        bool moved = false;

        //fold columns
        for(int i=topLeftR;i<=(topLeftR+botRightR)/2;++i) {
            if(canFold())
                solve(), moved = true;
        }
        for(int i=botRightR;i>=(topLeftR+botRightR)/2;--i) {
            if(canFold())
                solve(), moved = true;
        }

        //fold rows

        if(!moved)
            sol.insert(extract(topLeftR, topLeftC, botRightR, botRightC));
    }

	int howMany(vector <string> paper) {
        init = paper;
        R = paper.size();
        C = paper[0].size();
        sol.clear();

        solve(0, 0, R-1, C-1);
        return sol.size();
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
		cout << "Testing BoardFoldingDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417178218;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BoardFoldingDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string paper[] = {"10",
				                  "11"};
				_expected = 1;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}
			case 1:
			{
				string paper[] = {"1111111",
				                  "1111111"};
				_expected = 84;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}
			case 2:
			{
				string paper[] = {"0110",
				                  "1001",
				                  "1001",
				                  "0110"};
				_expected = 9;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}
			case 3:
			{
				string paper[] = {"0",
				                  "0",
				                  "0",
				                  "1",
				                  "0",
				                  "0"};
				_expected = 6;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}
			case 4:
			{
				string paper[] = {"000",
				                  "010",
				                  "000"};
				_expected = 1;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}
			/*case 5:
			{
				string paper[] = ;
				_expected = ;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string paper[] = ;
				_expected = ;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string paper[] = ;
				_expected = ;
				_received = _obj.howMany(vector <string>(paper, paper+sizeof(paper)/sizeof(string))); break;
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
