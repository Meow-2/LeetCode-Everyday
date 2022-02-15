// @before-stub-for-debug-begin

// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        const int size = nums.size();
        int       k    = 0;   // k指向第一个未排好的元素
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                if (i != k)
                    swap(nums[i], nums[k++]);
                else
                    k++;
            }
        }
    }
};

// @lc code=end

int main()
{
    vector<int> nums = {1, 0, 1, 0, 0, 3, 0, 4};
    Solution().moveZeroes(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
