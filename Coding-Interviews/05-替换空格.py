class Solution:
    def replaceSpace(self, s: str) -> str:
        i = 0
        while i < len(s):
            if s[i] == ' ':
                s = s[:i] + "%20" + s[(i+1):]
                i += 2
            i += 1
        return s
