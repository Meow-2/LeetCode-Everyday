/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        //双指针
        int k = 0;   //[0,k)是保留的元素
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (i != k)
                    swap(nums[i], nums[k++]);
                else
                    k++;
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
    vector<int> nums = {1, 9, 9, 3, 5, 9, 5};
    Solution().removeElement(nums, 9);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
