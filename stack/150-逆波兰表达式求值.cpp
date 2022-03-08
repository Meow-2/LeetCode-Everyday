/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stack;
        for (auto i : tokens) {
            if (i == "+") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (i == "-") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (i == "*") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (i == "/") {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else
                stack.push(stoi(i));
        }
        return stack.top();
    }
};
// @lc code=end
