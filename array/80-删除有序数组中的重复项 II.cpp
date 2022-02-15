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
        int k       = 2;
        int sameNum = 0;
        for (int i = 2; i < nums.size(); i++) {
            bool flag = false;
            if (nums[i] != nums[i - 1]) {
                sameNum = 0;
                flag    = true;
            }
            else if (sameNum < 2) {
                sameNum++;
                flag = true;
            }
            if (flag) {
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
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 7, 8, 8, 8};
    Solution().removeDuplicates(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl << nums.size() << endl;
    return 0;
}