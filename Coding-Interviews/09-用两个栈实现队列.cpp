#include <stack>
using namespace std;
class CQueue
{
public:
    stack<int> in;
    stack<int> out;
    CQueue() {}

    void appendTail(int value) { in.push(value); }

    int deleteHead()
    {
        if (out.empty()) {
            while (!in.empty()) {
                auto top = in.top();
                in.pop();
                out.push(top);
            }
        }
        if (out.empty())
            return -1;
        auto ret = out.top();
        out.pop();
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
