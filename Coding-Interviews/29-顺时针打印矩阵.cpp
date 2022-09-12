#include <vector>
using namespace std;
class Solution
{
public:
    int         m;
    int         n;
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        m = matrix.size();
        n = matrix.empty() ? 0 : matrix[0].size();
        vector<int> ret;

        int border = 0;

        int M = m - 2 * border;
        int N = n - 2 * border;

        while (M > 0 && N > 0) {
            for (int i = 0; i < N; i++)
                ret.push_back(matrix[border][border + i]);
            for (int i = 0; i < M - 2; i++)
                ret.push_back(matrix[border + i + 1][border + N - 1]);
            if (M > 1) {
                for (int i = 0; i < N; i++)
                    ret.push_back(matrix[border + M - 1][border + N - 1 - i]);
            }
            if (N > 1) {
                for (int i = 0; i < M - 2; i++)
                    ret.push_back(matrix[border + M - 2 - i][border]);
            }
            border++;
            M = m - 2 * border;
            N = n - 2 * border;
        }
        return ret;
    }
};
