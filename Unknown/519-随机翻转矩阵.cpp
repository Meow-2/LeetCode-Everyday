/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 */

// @lc code=start
#include <map>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    Solution(int m, int n) : m(m), n(n), boundary(m * n)
    {
    }
    //洗牌算法，构造一个数组，其元素等于索引，每次随机将随机到的元素和最末尾元素交换，最大索引减一即可保证随机到的元素不重复且概率均等
    //为了节约空间，只需要记录最大索引前，元素不等于索引的元素即可
    vector<int> flip()
    {
        int randNum = rand() % boundary + 1;
        if (hashMap.find(randNum) == hashMap.end())
            hashMap[randNum] = hashMap.find(boundary) == hashMap.end() ? boundary : hashMap[boundary];
        else
        {
            int temp = randNum;
            randNum = hashMap[randNum];
            hashMap[temp] = hashMap.find(boundary) == hashMap.end() ? boundary : hashMap[boundary];
        }
        int row = randNum % n == 0 ? ((randNum) / n - 1) : ((randNum) / n);
        int column = randNum % n == 0 ? n - 1 : randNum % n - 1;
        boundary--;
        return {row, column};
    }

    void reset()
    {
        hashMap.clear();
        boundary = m * n;
    }

private:
    int m;
    int n;
    int boundary;
    map<int, int> hashMap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end
