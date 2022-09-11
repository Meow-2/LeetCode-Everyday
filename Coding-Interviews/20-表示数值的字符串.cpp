#include <string>
using namespace std;
class Solution
{
public:
    bool isNumber(string s)
    {
        int cur = 0;
        while (s[cur] == ' ')
            cur++;
        if (s[cur] == '+' || s[cur] == '-')
            cur++;
        if ('0' <= s[cur] && s[cur] <= '9') {
            cur++;
            while ('0' <= s[cur] && s[cur] <= '9')
                cur++;
            if (s[cur] == '.')
                cur++;
            while ('0' <= s[cur] && s[cur] <= '9')
                cur++;
        }
        else if (s[cur] == '.') {
            cur++;
            if (s[cur] < '0' || s[cur] > '9')
                return false;
            while ('0' <= s[cur] && s[cur] <= '9')
                cur++;
        }
        else
            return false;
        if (s[cur] == 'e' || s[cur] == 'E') {
            cur++;
            if (s[cur] == '+' || s[cur] == '-')
                cur++;
            if (s[cur] < '0' || s[cur] > '9')
                return false;
            while ('0' <= s[cur] && s[cur] <= '9')
                cur++;
        }
        while (s[cur] == ' ')
            cur++;
        return cur == s.size() ? true : false;
    }
};
