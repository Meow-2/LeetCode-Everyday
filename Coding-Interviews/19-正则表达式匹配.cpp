#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool match(int a, int b, string s, string p) { return p[b] == '.' || s[a] == p[b]; }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < p.size() + 1; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }
        for (int i = 1; i < s.size() + 1; i++) {
            for (int j = 1; j < p.size() + 1; j++) {
                if (p[j - 1] == '*')
                    dp[i][j] =
                        dp[i][j - 2] || (dp[i - 1][j] && match(i - 1, j - 2, s, p)) || dp[i][j - 1];
                else if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
        return dp[s.size()][p.size()];
    }
};
