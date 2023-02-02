import collections


class Solution:
    def firstUniqChar(self, s: str) -> str:
        cnt = collections.Counter(s)
        for ch in s:
            if cnt[ch] == 1:
                return ch
        return " "
