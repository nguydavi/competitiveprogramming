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

class RobotOnMoonEasy {
public:
    bool isIn(int r, int c, int N, int M) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }

	string isSafeCommand(vector <string> board, string S) {
        int r = -1, c = -1;
        int N = board.size();
        int M = board[0].size();
        for(int i=0;i<N;++i)
            for(int j=0;j<M;++j)
                if(board[i][j] == 'S') {
                    r = i;
                    c = j;
                    board[i][j] = '.';
                }

        for(char com : S) {
            int oldR = r;
            int oldC = c;
            if(com == 'U') {
                --r;
            } else if(com == 'D') {
                ++r;
            } else if(com == 'L') {
                --c;
            } else if(com == 'R') {
                ++c;
            }

            if(!isIn(r, c, N, M))
                return "Dead";
            if(board[r][c] == '#')
                r = oldR, c = oldC;
        }
        return "Alive";
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
		cout << "Testing RobotOnMoonEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1425142804;
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
		RobotOnMoonEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".....",
				                  ".###.",
				                  "..S#.",
				                  "...#."};
				string S = "URURURURUR";
				_expected = "Alive";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			case 1:
			{
				string board[] = {".....",
				                  ".###.",
				                  "..S..",
				                  "...#."};
				string S = "URURURURUR";
				_expected = "Dead";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			case 2:
			{
				string board[] = {".....",
				                  ".###.",
				                  "..S..",
				                  "...#."};
				string S = "URURU";
				_expected = "Alive";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			case 3:
			{
				string board[] = {"#####",
				                  "#...#",
				                  "#.S.#",
				                  "#...#",
				                  "#####"};
				string S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
				_expected = "Alive";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			case 4:
			{
				string board[] = {"#####",
				                  "#...#",
				                  "#.S.#",
				                  "#...#",
				                  "#.###"};
				string S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
				_expected = "Dead";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			case 5:
			{
				string board[] = {"S"};
				string S = "R";
				_expected = "Dead";
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}
			/*case 6:
			{
				string board[] = ;
				string S = ;
				_expected = ;
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				string S = ;
				_expected = ;
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				string S = ;
				_expected = ;
				_received = _obj.isSafeCommand(vector <string>(board, board+sizeof(board)/sizeof(string)), S); break;
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
