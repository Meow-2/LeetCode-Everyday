/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <cstdlib>
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
        //洗牌算法(从中间拿一叠放到最上面，这里是从中间拿一个数放到数组末尾)
        //相当于每次随机从剩下的所有数中选一个数放到新数组里
        //i为剩下的数的个数[0,temp.size-1)，num为从剩下的数中选出的数
        for (int i = temp.size() - 1; i > 0; i--)
        {
            int num = rand() % (i + 1);
            if (num != i)
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
