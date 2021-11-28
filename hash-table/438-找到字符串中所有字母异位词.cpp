/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    Solution()
    {
    }

    bool isEmpty(int arr[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        int diff[26] = {0};
        vector<int> temp;
        int sLength = s.size();
        int pLength = p.size();
        if (sLength < pLength)
            return {};
        for (int i = 0; i < pLength; i++)
        {
            diff[p[i] - 'a']--;
            diff[s[i] - 'a']++;
        }
        int index = 0;
        do
        {
            if (isEmpty(diff))
                temp.push_back(index);
            if (index == sLength - pLength)
                break;
            diff[s[index] - 'a']--;
            diff[s[index + pLength] - 'a']++;
            index++;
        } while (true);
        return temp;
    }
};
// @lc code=end
