#include <stack>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x)
    {
        count++;
        data.push(x);
        if (min_cur.empty())
            min_cur.push(x);
        else
            min_cur.push(::min(x, min_cur.top()));
    }

    void pop()
    {
        if (!count)
            return;
        count--;
        min_cur.pop();
        data.pop();
    }

    int top() { return data.top(); }

    int min() { return min_cur.top(); }

private:
    int        count{0};
    stack<int> data;
    stack<int> min_cur;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
