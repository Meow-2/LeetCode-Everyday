/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <iostream>
#include <vector>
class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int k = 1;   //[0,k)为保留的元素
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (i != k) {
                    nums[k++] = nums[i];
                }
                else {
                    k++;
                }
            }
        }
        for (int i = nums.size() - 1; i >= k; i--) {
            nums.pop_back();
        }
        return nums.size();
    }
};
// @lc code=end

int main()
{
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 4, 5, 6, 7};
    Solution().removeDuplicates(nums);
    for (auto i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << nums.size() << std::endl;
    return 0;
}