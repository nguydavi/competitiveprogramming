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

class PathGameDiv2 {
	public:
    static const char BLACK = '#';
    static const char WHITE = '.';
    int N;

	int calc(vector <string> board) {
        N = board[0].size();
        set<pair<int, int> > ss;
        for(int i=0;i<2;++i)
            for(int j=0;j<N;++j)
                if(board[i][j] == BLACK)
                    ss.insert(make_pair(i,j));
        if(ss.empty())
            return N;

        int ans = 0;
        for(set<pair<int, int> >::iterator it=ss.begin();it!=ss.end();++it) {
            int ii = (*it).first;
            int jj = (*it).second;
            int curAns = 0;
            while(jj>=0) {
                if(board[ii][jj] == WHITE)
                    ++curAns;

                if(jj-2 >= 0 && board[ii^1][jj-2] == BLACK)
                    ii ^= 1, jj -=2;
                else
                    --jj;
            }

            ii = (*it).first;
            jj = (*it).second;
            while(jj < N) {
                if(board[ii][jj] == WHITE)
                    ++curAns;

                if(jj+2 <N && board[ii^1][jj+2] == BLACK)
                    ii ^= 1, jj +=2;
                else
                    ++jj;
            }
            ans = max(ans, curAns);
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
		cout << "Testing PathGameDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1414092747;
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
		PathGameDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#...."
				                 ,"...#."};
				_expected = 2;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"#"
				                 ,"."};
				_expected = 0;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"."
				                 ,"."};
				_expected = 1;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"....#.##.....#..........."
				                 ,"..#......#.......#..#...."};
				_expected = 13;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 4:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.calc(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
