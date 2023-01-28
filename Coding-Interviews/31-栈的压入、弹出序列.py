class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        real = []
        idxPush = 0
        for i in popped:
            while not real or real[-1] != i:
                if idxPush < len(pushed):
                    real.append(pushed[idxPush])
                    idxPush += 1
                else:
                    return False
            real.pop()
        return True
