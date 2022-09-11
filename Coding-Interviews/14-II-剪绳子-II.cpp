#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class Solution
{
public:
    int cuttingRope(int n)
    {
        vector<long long> dp(n + 1);
        dp[1] = 1;
        for (long long i = 2; i < n + 1; i++) {
            long long dp_max = INT_MIN;
            for (long long j = 1; j < i; j++) {
                dp_max = std::max(dp_max, std::max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = dp_max;
        }
        return dp[n] % 1000000007;
    }
};
