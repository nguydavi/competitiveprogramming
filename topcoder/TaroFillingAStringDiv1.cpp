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

typedef long long ll;
typedef pair<int, char> pic;
int MOD = 1e9+7;

class TaroFillingAStringDiv1 {
public:
	int getNumber(int N, vector <int> position, string value) {
        vector<pic> vv;
        for(int i=0;i<position.size();++i)
            vv.push_back({position[i], value[i]});
        sort(vv.begin(), vv.end());

        ll ans = 1;
        for(int i=1;i<vv.size();++i) {
            int len = vv[i].first-vv[i-1].first-1;
            bool diff = vv[i].second == vv[i-1].second;
            if(len > 0 && len%2 == !diff)
                ans *= (len+1);
            ans %= MOD;
        }
        return (int)ans;
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
		cout << "Testing TaroFillingAStringDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1424286307;
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
		TaroFillingAStringDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int position[] = {1, 3};
				string value = "AB";
				_expected = 2;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}
			case 1:
			{
				int N = 4;
				int position[] = {2, 1, 3, 4};
				string value = "ABBA";
				_expected = 1;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}
			case 2:
			{
				int N = 25;
				int position[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
				string value = "ABBBBABABBAAABA";
				_expected = 1;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}
			case 3:
			{
				int N = 305;
				int position[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
				string value = "ABAABBABBAABABBBBAAAABBABBBA";
				_expected = 43068480;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}
			/*case 4:
			{
				int N = ;
				int position[] = ;
				string value = ;
				_expected = ;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}*/
			/*case 5:
			{
				int N = ;
				int position[] = ;
				string value = ;
				_expected = ;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
			}*/
			/*case 6:
			{
				int N = ;
				int position[] = ;
				string value = ;
				_expected = ;
				_received = _obj.getNumber(N, vector <int>(position, position+sizeof(position)/sizeof(int)), value); break;
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
