/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
template<class T>
ostream& operator<<(ostream& x, vector<T> const& y)
{
    x << "[ ";
    for (auto i : y)
        x << i << ' ';
    x << "]\n";
    return x;
}

class Solution
{
public:
    vector<int> maxHeap;

    void push(int key)
    {
        maxHeap.push_back(key);
        shiftUp(maxHeap.size() - 1);
    };
    int pop()
    {
        if (!maxHeap.size())
            return INT_MIN;
        int top = maxHeap[0];
        std::swap(maxHeap[0], maxHeap[maxHeap.size() - 1]);
        maxHeap.pop_back();
        shiftDown(0);
        return top;
    }
    void shiftDown(int pos)
    {
        int cur        = pos;
        int leftChild  = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int maxChild   = leftChild;
        if (rightChild < maxHeap.size() && maxHeap[rightChild] > maxHeap[leftChild])
            maxChild = rightChild;
        while (maxChild < maxHeap.size() && maxHeap[cur] < maxHeap[maxChild]) {
            std::swap(maxHeap[cur], maxHeap[maxChild]);
            cur        = maxChild;
            leftChild  = 2 * cur + 1;
            rightChild = 2 * cur + 2;
            maxChild   = leftChild;
            if (rightChild < maxHeap.size() && maxHeap[rightChild] > maxHeap[leftChild])
                maxChild = rightChild;
        }
    }
    void shiftUp(int pos)
    {
        int father = (pos + 1) / 2 - 1;
        int cur    = pos;
        while (father >= 0 && maxHeap[father] < maxHeap[cur]) {
            std::swap(maxHeap[father], maxHeap[cur]);
            cur    = father;
            father = (cur + 1) / 2 - 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        // std::priority_queue<int> q(nums.begin(), nums.end());
        // for (int i = 0; i < k - 1; i++)
        //     q.pop();
        // return q.top();
        for (auto i : nums) {
            push(i);
            // cout << maxHeap;
        }
        for (int i = 0; i < k - 1; i++) {
            pop();
            // cout << maxHeap;
        }
        return pop();
    }
};
// @lc code=end
