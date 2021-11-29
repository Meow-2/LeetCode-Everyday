// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem786.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
#include <cassert>
class Solution
{
private:
    struct Fraction
    {
        int i;
        int j;
        float value;
        Fraction() {}
        Fraction(int i, int j) : i(i), j(j), value(i / (float)j)
        {
        }
        bool operator<(const Fraction &fraction) const
        {
            return value < fraction.value;
        }
        bool operator>(const Fraction &fraction) const
        {
            return value > fraction.value;
        }
    };
    Fraction *maxHeap;
    int count;
    int capacity;

    void shiftDown(int k)
    {
        assert(k <= count);
        Fraction temp = maxHeap[k];
        while (2 * k <= count)
        {
            int j = 2 * k;
            if (j + 1 <= count && maxHeap[j + 1] > maxHeap[j])
                j++;
            if (maxHeap[j] > temp)
            {
                maxHeap[k] = maxHeap[j];
                k = j;
            }
            else
                break;
        }
        maxHeap[k] = temp;
    }
    void shiftUp(int k)
    {
        assert(k <= count);
        Fraction temp = maxHeap[k];
        while (k / 2 >= 1)
        {
            if (maxHeap[k / 2] < temp)
            {
                maxHeap[k] = maxHeap[k / 2];
                k = k / 2;
            }
            else
                break;
        }
        maxHeap[k] = temp;
    }

    void insert(Fraction fraction)
    {
        assert(count < capacity);
        count++;
        maxHeap[count] = fraction;
        shiftUp(count);
    }
    vector<int> extractMax()
    {
        assert(count > 0);
        vector<int> temp = {maxHeap[1].i,
                            maxHeap[1].j};
        maxHeap[1] = maxHeap[count];
        count--;
        if (count > 0)
            shiftDown(1);
        return temp;
    }

public:
    Solution() : capacity(0), count(0), maxHeap(nullptr) {}
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        //最大堆
        maxHeap = new Fraction[k + 2];
        capacity = k + 1;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (count < capacity - 1)
                    insert(Fraction(arr[i], arr[j]));
                else
                {
                    insert(Fraction(arr[i], arr[j]));
                    extractMax();
                }
            }
        }
        return extractMax();
    }
};
// @lc code=end
