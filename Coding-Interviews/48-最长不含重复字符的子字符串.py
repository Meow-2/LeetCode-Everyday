class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not len(s):
            return 0
        # [left,right)
        left, right = 0, 0
        res = right - left
        charset = set()
        while right < len(s):
            ch = s[right]
            right += 1
            while ch in charset:
                charset.remove(s[left])
                left += 1
            charset.add(ch)
            res = max(res, right - left)
        return res
