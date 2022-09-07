#include <vector>
using namespace std;
class Solution
{
public:
    bool find(vector<int> const& x, int target)
    {
        if (x.empty())
            return false;
        int left = 0, right = x.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x[mid] == target)
                return true;
            if (x[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {

        for (auto const& i : matrix) {
            bool is_found = find(i, target);
            if (is_found)
                return true;
        }
        return false;
    }
};
