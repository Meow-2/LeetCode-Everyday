from typing import List


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        # check[i,j]
        def check(i: int, j: int):
            if i >= j:
                return True
            idx = i
            while idx < j and postorder[idx] < postorder[j]:
                idx += 1
            m = idx
            while m < j and postorder[m] > postorder[j]:
                m += 1
            return m == j and check(i, idx-1) and check(idx, j-1)

        return check(0, len(postorder)-1)
