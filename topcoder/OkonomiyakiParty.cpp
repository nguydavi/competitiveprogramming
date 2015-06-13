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
#include <cassert>

using namespace std;

const int MAXN = 60;
const int MOD = (int)1e9+7;

class OkonomiyakiParty {
public:
    int N, M, K;
    vector<int> arr;
    int dp[MAXN][MAXN][MAXN];

    /**
     * It is necessary to sort the array and start from minIndex+1 at each time
     * otherwise, we would count all duplicates if we would call solve(0, 1, i)
     * (and checking that index != minIndex && arr[index] >= arr[minIndex]):
     *
     * ex: {4,4,4,4}
     *      solve(0,1,0) would count AB, AC, AD
     *      solve(0,1,1) would count AB (!), BC, BD
     *      ...
     * Note: it would work for distinct elements though
     */
    int solve(int index, int cnt, int minIndex) {
        if(cnt == M)
            return 1;
        if(index == N || arr[index]-arr[minIndex] > K)
            return 0;
        if(dp[index][cnt][minIndex] != -1)
            return dp[index][cnt][minIndex];

        // in sorted array, index must be greater and elements must be greater or
        // equal
        //assert(index > minIndex);

        int res = solve(index+1, cnt+1, minIndex);
        res %= MOD;
        res += solve(index+1, cnt, minIndex);
        res %= MOD;

        dp[index][cnt][minIndex] = res;
        return res;
    }

	int count(vector <int> osize, int M, int K) {
        this->M = M;
        this->K = K;
        arr = osize;
        sort(arr.begin(), arr.end());
        N = arr.size();

        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i=0;i<N-1;++i) {
            // we take only elements that are greater or equal to the current element (since array is sorted)
            // take current index as minimum element 
            ans += solve(i+1, 1, i);
            ans %= MOD;
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
		cout << "Testing OkonomiyakiParty (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1420200004;
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
		OkonomiyakiParty _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int osize[] = {1,4,6,7,9};
				int M = 2;
				int K = 3;
				_expected = 6;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 1:
			{
				int osize[] = {1,6,2,7,4,2,6,1,5,2,4};
				int M = 4;
				int K = 3;
				_expected = 60;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 2:
			{
				int osize[] = {1,4,5,7,10,11,13,16,18};
				int M = 4;
				int K = 5;
				_expected = 0;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 3:
			{
				int osize[] = {55,2,7,232,52,5,5332,623,52,6,532,5147};
				int M = 6;
				int K = 10000;
				_expected = 924;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 4:
			{
				int osize[] = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
				              1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
				              5682,7775,4356,5140,8923,9801,3729};
				int M = 15;
				int K = 4003;
				_expected = 114514;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 5:
			{
				int osize[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int M = 25;
				int K = 2;
				_expected = 605552882;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 6:
			{
				int osize[] = {1,4,6,7,9};
				int M = 2;
				int K = 10;
				_expected = 10;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 7:
			{
				int osize[] = {1,4,6,7};
				int M = 2;
				int K = 10;
				_expected = 6;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
			}
			case 8:
			{
				int osize[] = {4,4,4,4};
				int M = 2;
				int K = 3;
				_expected = 6;
				_received = _obj.count(vector <int>(osize, osize+sizeof(osize)/sizeof(int)), M, K); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
