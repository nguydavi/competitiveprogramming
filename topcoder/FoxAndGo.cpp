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

typedef pair<int, int> pii;
const int MAXN = 30;
int R, C;
int p[MAXN*MAXN];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class FoxAndGo {
public:
    void unionSet(int a, int b) {
        p[findSet(a)] = findSet(b);
    }

    int findSet(int a) {
        if(p[a] == a)
            return a;
        return p[a] = findSet(p[a]);
    }

    int getId(int r, int c) {
        return r*R + c;
    }

    bool isIn(int r, int c) {
        return r>=0 && r<R && c >= 0 && c < C;
    }

	int maxKill(vector <string> board) {
        R = board.size(), C = board[0].size();
        for(int i=0;i<MAXN*MAXN;++i)
            p[i] = i;

        vector<pii> empty;
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j) {
                if(board[i][j] == '.')
                    empty.push_back({i,j});
                else if(board[i][j] == 'o') {
                    for(int k=0;k<4;++k) {
                        int nr = i+dr[k], nc = j+dc[k];
                        if(isIn(nr, nc) && board[nr][nc] == 'o')
                            unionSet(getId(i, j), getId(nr, nc));
                    }
                }

            }

        vector< vector<pii> > sets(MAXN*MAXN);
        for(int i=0;i<R;++i)
            for(int j=0;j<C;++j) {
                if(board[i][j] == 'o') {
                    sets[findSet(getId(i, j))].push_back({i, j});
                }
            }

        int ans = 0;
        for(pii start : empty) {
            board[start.first][start.second] = 'x';
            int sol = 0;
            for(vector<pii> s : sets) {
                bool ok = false;
                for(pii point : s) {
                    for(int i=0;i<4;++i) {
                        int nr = point.first+dr[i], nc = point.second + dc[i];
                        if(isIn(nr, nc) && board[nr][nc] == '.') {
                            ok = true;
                            break;
                        }
                    }

                    if(ok)
                        break;
                }
                if(!ok)
                    sol += s.size();
            }
            board[start.first][start.second] = '.';
            ans = max(ans, sol);
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
		cout << "Testing FoxAndGo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1434196572;
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
		FoxAndGo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".....",
				                  "..x..",
				                  ".xox.",
				                  ".....",
				                  "....."};
				_expected = 1;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"ooooo",
				                  "xxxxo",
				                  "xxxx.",
				                  "xxxx.",
				                  "ooooo"};
				_expected = 6;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".xoxo",
				                  "ooxox",
				                  "oooxx",
				                  "xoxox",
				                  "oxoox"};
				_expected = 13;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".......",
				                  ".......",
				                  ".......",
				                  "xxxx...",
				                  "ooox...",
				                  "ooox...",
				                  "ooox..."};
				_expected = 9;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".......",
				                  ".xxxxx.",
				                  ".xooox.",
				                  ".xo.ox.",
				                  ".xooox.",
				                  ".xxxxx.",
				                  "......."};
				_expected = 8;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"o.xox.o",
				                  "..xox..",
				                  "xxxoxxx",
				                  "ooo.ooo",
				                  "xxxoxxx",
				                  "..xox..",
				                  "o.xox.o"};
				_expected = 12;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {".......",
				                  "..xx...",
				                  ".xooox.",
				                  ".oxxox.",
				                  ".oxxxo.",
				                  "...oo..",
				                  "......."};
				_expected = 4;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {".ox....",
				                  "xxox...",
				                  "..xoox.",
				                  "..xoox.",
				                  "...xx..",
				                  ".......",
				                  "......."}
				                  ;
				_expected = 5;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"...................",
				                  "...................",
				                  "...o..........o....",
				                  "................x..",
				                  "...............x...",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "...................",
				                  "................o..",
				                  "..x................",
				                  "...............x...",
				                  "...................",
				                  "..................."};
				_expected = 0;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 9:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.maxKill(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
