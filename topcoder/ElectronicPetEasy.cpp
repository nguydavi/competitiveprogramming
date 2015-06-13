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

class ElectronicPetEasy {
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
        set<int> pet1;

        int time = st1;
        pet1.insert(time);
        for(int i=0;i<t1-1;++i) {
            time += p1;
            pet1.insert(time);
        }

        time = st2;
        if(pet1.find(time) != pet1.end())
            return "Difficult";
        for(int i=0;i<t2-1;++i) {
            time += p2;
            if(pet1.find(time) != pet1.end())
                return "Difficult";
        }
        return "Easy";
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
		cout << "Testing ElectronicPetEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1417176005;
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
		ElectronicPetEasy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int st1 = 3;
				int p1 = 3;
				int t1 = 3;
				int st2 = 5;
				int p2 = 2;
				int t2 = 3;
				_expected = "Difficult";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 1:
			{
				int st1 = 3;
				int p1 = 3;
				int t1 = 3;
				int st2 = 5;
				int p2 = 2;
				int t2 = 2;
				_expected = "Easy";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 2:
			{
				int st1 = 1;
				int p1 = 4;
				int t1 = 7;
				int st2 = 1;
				int p2 = 4;
				int t2 = 7;
				_expected = "Difficult";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 3:
			{
				int st1 = 1;
				int p1 = 1000;
				int t1 = 1000;
				int st2 = 2;
				int p2 = 1000;
				int t2 = 1000;
				_expected = "Easy";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 4:
			{
				int st1 = 1;
				int p1 = 1;
				int t1 = 1;
				int st2 = 2;
				int p2 = 2;
				int t2 = 2;
				_expected = "Easy";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 5:
			{
				int st1 = 1;
				int p1 = 1;
				int t1 = 1;
				int st2 = 1;
				int p2 = 1;
				int t2 = 1;
				_expected = "Difficult";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 6:
			{
				int st1 = 1;
				int p1 = 2;
				int t1 = 1000;
				int st2 = 2;
				int p2 = 2;
				int t2 = 1000;
				_expected = "Easy";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
			case 7:
			{
				int st1 = 1000;
				int p1 = 1000;
				int t1 = 1000;
				int st2 = 1001;
				int p2 = 1000;
				int t2 = 1000;
				_expected = "Easy";
				_received = _obj.isDifficult(st1, p1, t1, st2, p2, t2); break;
			}
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
