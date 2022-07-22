/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <algorithm>
#include <climits>
#include <set>
#include <stack>
using namespace std;
// @lc code=start
class MinStack
{
public:
    // 没有面向面试
    // stack<int>    st;
    // multiset<int> s;
    // MinStack() {}

    // void push(int val)
    // {
    //     st.push(val);
    //     s.insert(val);
    // }

    // void pop()
    // {
    //     auto t = st.top();
    //     st.pop();
    //     s.erase(s.find(t));
    // }

    // int top() { return st.top(); }

    // int getMin() { return *(s.begin()); }

    stack<int> st;
    stack<int> m;
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (m.empty()) {
            m.push(val);
        }
        else {
            m.push(min(m.top(), val));
        }
    }

    void pop()
    {
        st.pop();
        m.pop();
    }

    int top() { return st.top(); }

    int getMin() { return m.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
