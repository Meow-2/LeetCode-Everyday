/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    // 二分加上partition
    // int findKthLargest(vector<int>& nums, int k)
    // {
    //     int left  = 0;
    //     int right = nums.size() - 1;
    //     while (left < right) {
    //         int slow = left;
    //         int i    = left;
    //         while (i <= right) {
    //             if (nums[i] >= nums[left]) {
    //                 swap(nums[i], nums[slow++]);
    //             }
    //             i++;
    //         }
    //         swap(nums[left], nums[slow - 1]);
    //         if (slow - left == k)
    //             return nums[slow - 1];
    //         else if (slow - left > k) {
    //             right = slow - 2;
    //         }
    //         else {
    //             k    = k - slow + left;
    //             left = slow;
    //         }
    //     }
    //     return nums[left];
    // }


    int findKthLargest(vector<int>& nums, int k)
    {
        for (int i = 0; i < k; i++) {
            shiftUp(nums, i);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                shiftDown(nums, 0, k - 1);
            }
        }
        return nums[0];
    }
    void shiftUp(vector<int>& nums, int n)
    {
        //将 nums[n] 插入 nums[0,n-1]这个堆
        int temp        = nums[n];
        int parentIndex = (n + 1) / 2 - 1;
        while (parentIndex >= 0 && temp < nums[parentIndex]) {
            nums[n]     = nums[parentIndex];
            n           = parentIndex;
            parentIndex = (n + 1) / 2 - 1;
        }
        nums[n] = temp;
    }
    void shiftDown(vector<int>& nums, int n, int N)
    {
        // N为堆下界
        int temp       = nums[n];
        int leftChild  = 2 * n + 1;
        int rightChild = 2 * n + 2;
        int minChild   = leftChild;
        while (leftChild <= N) {
            if (rightChild <= N && nums[rightChild] < nums[leftChild])
                minChild = rightChild;
            if (temp > nums[minChild]) {
                nums[n]    = nums[minChild];
                n          = minChild;
                leftChild  = 2 * n + 1;
                rightChild = 2 * n + 2;
                minChild   = leftChild;
            }
            else {
                break;
            }
        }
        nums[n] = temp;
    }
};
// @lc code=end