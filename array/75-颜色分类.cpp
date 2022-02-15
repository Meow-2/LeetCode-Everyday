/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int slow0 = 0;   //[0,slow0)为0
        int slow1 = 0;   //[slow0,slow1)为1
        int fast  = 0;
        while (fast < nums.size()) {
            if (nums[fast] == 0) {
                swap(nums[slow1], nums[fast]);
                swap(nums[slow1++], nums[slow0++]);
            }
            else if (nums[fast] == 1) {
                swap(nums[slow1++], nums[fast]);
            }
            fast++;
        }
    }
};
// @lc code=end
int main()
{
    vector<int> nums = {1, 0};
    Solution().sortColors(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}