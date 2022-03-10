// @before-stub-for-debug-begin
#include "commoncppproblem341.h"

#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        vector<NestedInteger> temp;
        for (auto i = nestedList.rbegin(); i != nestedList.rend(); i++) {
            temp.push_back(*i);
        }
        while (!temp.empty()) {
            auto i = temp.back();
            temp.pop_back();
            if (i.isInteger())
                res.push_back(i.getInteger());
            else {
                auto k = i.getList();
                for (auto j = k.rbegin(); j != k.rend(); j++)
                    temp.push_back(*j);
            }
        }
        cur = res.begin();
    }

    int next()
    {
        return *cur++;
    }

    bool hasNext()
    {
        return cur != res.end();
    }

private:
    vector<int>::iterator cur;
    vector<int>           res{};
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
