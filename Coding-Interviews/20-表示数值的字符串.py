class Solution:
    def isNumber(self, s: str) -> bool:
        idx = 0
        while idx < len(s) and s[idx] == ' ':
            idx += 1
        if idx < len(s) and (s[idx] == '+' or s[idx] == '-'):
            idx += 1
        if idx < len(s) and '0' <= s[idx] <= '9':
            idx += 1
            while idx < len(s) and '0' <= s[idx] <= '9':
                idx += 1
            if idx < len(s) and s[idx] == '.':
                idx += 1
                while idx < len(s) and '0' <= s[idx] <= '9':
                    idx += 1
        elif idx < len(s) and s[idx] == '.':
            idx += 1
            if idx < len(s) and '0' <= s[idx] <= '9':
                idx += 1
            else:
                return False
            while idx < len(s) and '0' <= s[idx] <= '9':
                idx += 1
        else:
            return False
        if idx < len(s) and (s[idx] == 'e' or s[idx] == 'E'):
            idx += 1
            if idx < len(s) and (s[idx] == '-' or s[idx] == '+'):
                idx += 1
            if idx < len(s) and '0' <= s[idx] <= '9':
                idx += 1
                while idx < len(s) and '0' <= s[idx] <= '9':
                    idx += 1
            else:
                return False
        while idx < len(s) and s[idx] == ' ':
            idx += 1
        return len(s) == idx
