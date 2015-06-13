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

const int MAXN = (int)2e5+10;

class WaitingForBus {
public:
    double dp[MAXN];

	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for(int j=0;j<s;++j)
            for(int i=0;i<time.size();++i)
                dp[j+time[i]] += dp[j]*prob[i]/100;

        double ans = 0;
        for(int i=0;i<(int)1e5+10;++i)
            ans += dp[s+i] * i;
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
		cout << "Testing WaitingForBus (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1419076442;
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
		WaitingForBus _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int time[] = {5,100};
				int prob[] = {90,10};
				int s = 5;
				_expected = 9.5;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}
			case 1:
			{
				int time[] = {5};
				int prob[] = {100};
				int s = 101;
				_expected = 4.0;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}
			case 2:
			{
				int time[] = {5,10};
				int prob[] = {50,50};
				int s = 88888;
				_expected = 3.666666666666667;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}
			case 3:
			{
				int time[] = {1,2,3,4};
				int prob[] = {10,20,30,40};
				int s = 1000;
				_expected = 1.166666666666667;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}
			case 4:
			{
				int time[] = {10,100,1000,10000,100000};
				int prob[] = {90,4,3,2,1};
				int s = 100000;
				_expected = 21148.147303578935;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}
			/*case 5:
			{
				int time[] = ;
				int prob[] = ;
				int s = ;
				_expected = ;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}*/
			/*case 6:
			{
				int time[] = ;
				int prob[] = ;
				int s = ;
				_expected = ;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}*/
			/*case 7:
			{
				int time[] = ;
				int prob[] = ;
				int s = ;
				_expected = ;
				_received = _obj.whenWillBusArrive(vector <int>(time, time+sizeof(time)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int)), s); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
