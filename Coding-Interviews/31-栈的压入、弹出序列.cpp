#include <stack>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> s;
        int        cur1 = 0;
        int        cur2 = 0;
        while (cur2 < popped.size()) {
            while (s.empty() || s.top() != popped[cur2]) {
                if (cur1 >= pushed.size())
                    return false;
                s.push(pushed[cur1]);
                cur1++;
            }
            s.pop();
            cur2++;
        }
        return true;
    }
};
