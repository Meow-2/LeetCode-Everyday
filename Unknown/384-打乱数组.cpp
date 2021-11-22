/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    Solution(vector<int> &nums) : arr(nums) {}

    vector<int> reset()
    {
        return arr;
    }

    vector<int> shuffle()
    {
        //srand(time(NULL));加上这句就无法通过
        vector<int> temp = arr;
        int length = temp.size();
        for (int i = 1; i < length; i++)
        {
            int num = rand() % (i + 1);
            swap(temp[num], temp[i]);
        }
        return temp;
    }

private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
