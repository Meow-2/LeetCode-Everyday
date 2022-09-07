#include <vector>
using namespace std;
class Solution
{
public:
    int findRepeatNumber(vector<int>& nums)
    {
        vector<int> hash(nums.size(), 0);
        for (auto const i : nums) {
            if (hash[i] != 0)
                return i;
            hash[i]++;
        }
        return -1;
    }
};
