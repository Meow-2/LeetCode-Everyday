#include <cmath>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        bool flag = false;
        if (n < 0) {
            n    = abs(n);
            flag = true;
        }
        double ret  = 1;
        auto   temp = myPow(x, n / 2);
        if (n % 2 == 1) {
            ret = x;
        }
        ret *= temp * temp;
        return flag ? 1 / ret : ret;
    }
};
