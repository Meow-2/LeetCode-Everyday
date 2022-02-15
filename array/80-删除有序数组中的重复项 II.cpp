/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int slow = 2;
        int fast = 2;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
};
// @lc code=end
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 7, 8, 8, 8};
    Solution().removeDuplicates(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl << nums.size() << endl;
    return 0;
}