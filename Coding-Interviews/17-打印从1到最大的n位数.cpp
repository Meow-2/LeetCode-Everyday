#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        string      max_num(n, '9');
        vector<int> ret;
        for (int i = 1; i <= stoi(max_num); i++)
            ret.push_back(i);
        return ret;
    }
};
