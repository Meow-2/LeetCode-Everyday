#include <climits>
#include <iostream>
#include <vector>
using namespace std;
template<class T>
ostream& operator<<(ostream& x, vector<T> const& y)
{
    x << '[';
    for (auto const& i : y) {
        x << ' ' << i;
    }
    x << " ]";
    return x;
}

class Solution
{
public:
    // int cuttingRope(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     int                 res = INT_MIN;
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //     dp[1][1] = 1;
    //     for (int i = 2; i < n + 1; i++)
    //         dp[i][1] = i;
    //     for (int i = 2; i < n + 1; i++) {
    //         for (int j = 2; j <= i; j++) {
    //             int dp_max = INT_MIN;
    //             for (int k = 1; k <= i - j + 1; k++) {
    //                 dp_max = max(dp_max, dp[i - k][j - 1] * k);
    //             }
    //             dp[i][j] = dp_max;
    //             res      = max(dp[i][j], res);
    //         }
    //     }
    //     return res;
    // }
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            int dp_max = INT_MIN;
            for (int j = 1; j < i; j++) {
                dp_max = max(dp_max, max(j * dp[i - j], j * (i - j)));
            }
            dp[i] = dp_max;
        }
        cout << dp;
        return dp[n];
    }
};

int main()
{
    Solution x;
    x.cuttingRope(5);
}
