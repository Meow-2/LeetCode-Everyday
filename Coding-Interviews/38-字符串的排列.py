from typing import List

# 使用 set 去重
# 也可以使用visit数组来标记用过的字符


class Solution:
    def permutation(self, s: str) -> List[str]:
        res = list()
        path = []
        s = list(s)

        def backtrace(idx: int):
            if idx == len(s):
                res.append(''.join(path))
                return
            for i in range(idx, len(s)):
                s[idx], s[i] = s[i], s[idx]
                path.append(s[idx])
                backtrace(idx+1)
                path.pop()
                s[idx], s[i] = s[i], s[idx]
        backtrace(0)
        return list(set(res))


if __name__ == '__main__':
    Solution().permutation("abc")
