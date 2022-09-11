#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> exchange(vector<int>& nums)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                swap(nums[index], nums[i]);
                index++;
            }
        }
        return nums;
    }
};
