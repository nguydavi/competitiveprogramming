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

class FoxAndGomoku {
public:
    bool isIn(const vector<string>& board, int r, int c) {
        return r >= 0 && r < board.size() && c >= 0 && c < board[0].size();
    }

    bool check(const vector<string>& board, int r, int c) {
        bool ok = true;
        for(int i=0;i<5;++i)
            if(!isIn(board, r, c+i) || board[r][c+i] == '.') {
                ok = false;
                break;
            }

        if(ok)
            return true;

        ok = true;
        for(int i=0;i<5;++i)
            if(!isIn(board, r+i, c+i) || board[r+i][c+i] == '.') {
                ok = false;
                break;
            }

        if(ok)
            return true;

        ok = true;
        for(int i=0;i<5;++i)
            if(!isIn(board, r+i, c) || board[r+i][c] == '.') {
                ok = false;
                break;
            }

        if(ok)
            return true;

        ok = true;
        for(int i=0;i<5;++i)
            if(!isIn(board, r+i, c-i) || board[r+i][c-i] == '.') {
                ok = false;
                break;
            }

        if(ok)
            return true;
        return false;
    }

    string win(vector<string> board) {
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board[0].size();++j) {
                if(board[i][j] == 'o' && check(board, i, j))
                    return "found";
            }
        }
        return "not found";
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
		cout << "Testing FoxAndGomoku (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1434196199;
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
		FoxAndGomoku _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"....o.",
				                  "...o..",
				                  "..o...",
				                  ".o....",
				                  "o.....",
				                  "......"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"oooo.",
				                  ".oooo",
				                  "oooo.",
				                  ".oooo",
				                  "....."}
				                  ;
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"oooo.",
				                  ".oooo",
				                  "oooo.",
				                  ".oooo",
				                  "....o"}
				                  ;
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"o.....",
				                  ".o....",
				                  "..o...",
				                  "...o..",
				                  "....o.",
				                  "......"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"o....",
				                  "o.o..",
				                  "o.o.o",
				                  "o.o..",
				                  "o...."};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"..........",
				                  "..........",
				                  "..oooooo..",
				                  "..o.......",
				                  "..o.......",
				                  "..oooooo..",
				                  ".......o..",
				                  ".......o..",
				                  "..oooooo..",
				                  ".........."}
				                  ;
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"..........",
				                  "..........",
				                  "..oooo.o..",
				                  "..o.......",
				                  "..o.......",
				                  "..o.oooo..",
				                  ".......o..",
				                  ".......o..",
				                  "..oooo.o..",
				                  ".........."};
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"ooooo",
				                  "ooooo",
				                  "ooooo",
				                  "ooooo",
				                  "ooooo"};
				_expected = "found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {".....",
				                  ".....",
				                  ".....",
				                  ".....",
				                  "....."};
				_expected = "not found";
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.win(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
