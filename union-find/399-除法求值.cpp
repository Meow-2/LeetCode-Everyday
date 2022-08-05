/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
template<class T>
ostream& operator<<(ostream& x, unordered_map<string, T> y)
{
    for (auto const& i : y) {
        x << '[' << i.first << ", " << i.second << "] ";
    }
    return x;
}
class Solution
{
public:
    // a/b = 3 , b/c = 2 , e/d = 4 , d/c =
    // a is root , a's weight = 1 , b's weight = a/b = 3
    // b is c's father, c's weight = b/c = 2
    // string to string 根
    unordered_map<string, string> uf;
    // string to father/string
    unordered_map<string, double> weight;
    string                        find(string const& x)
    {
        if (!uf.count(x))
            return "";
        if (uf[x] == x)
            return x;
        auto root = find(uf[x]);
        weight[x] = weight[x] * weight[uf[x]];
        uf[x]     = root;
        // 维护weight
        return root;
    }
    bool merge(string const& x, string const& y, double w)
    {
        if (find(x) != x || find(y) != y)
            return false;
        uf[y] = x;
        // weight[y] = x/y
        weight[y] = w;
        return true;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries)
    {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            // a/b, i[0] is a , i[1] is b
            if (!uf.count(eq[0]) && !uf.count(eq[1])) {
                uf[eq[0]]     = eq[0];
                uf[eq[1]]     = eq[0];
                weight[eq[0]] = 1.0;
                weight[eq[1]] = values[i];
            }
            else if (uf.count(eq[0]) && !uf.count(eq[1])) {
                uf[eq[1]]     = eq[0];
                weight[eq[1]] = values[i];
            }
            else if (!uf.count(eq[0]) && uf.count(eq[1])) {
                uf[eq[0]]     = eq[0];
                weight[eq[0]] = 1.0;
                auto r        = find(eq[1]);
                merge(r, eq[0], weight[eq[1]] / values[i]);
            }
            else if (uf.count(eq[0]) && uf.count(eq[1])) {
                auto r1 = find(eq[0]);
                auto r2 = find(eq[1]);
                if (r1 == r2)
                    continue;
                merge(r1, r2, weight[eq[0]] * values[i] / weight[eq[1]]);
            }
            // cout << "uf : " << uf << '\n';
            // cout << "weight : " << weight << '\n';
        }
        for (auto i : queries) {
            auto r1 = find(i[0]);
            auto r2 = find(i[1]);
            if (r1 == "" || r2 == "" || r1 != r2)
                res.push_back(-1.0);
            else
                res.push_back(weight[i[1]] / weight[i[0]]);
        }
        return res;
    }
};
// @lc code=end
