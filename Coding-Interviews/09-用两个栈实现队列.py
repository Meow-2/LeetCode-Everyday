# 当要出队时, 把栈的所有内容弹出并压入另一个栈就得到了出队的顺序
class CQueue:
    def __init__(self):
        self.stkTail = []
        self.stkHead = []

    def appendTail(self, value: int) -> None:
        self.stkTail.append(value)

    def deleteHead(self) -> int:
        if not self.stkHead and not self.stkTail:
            return -1
        if self.stkHead:
            res = self.stkHead[-1]
            self.stkHead.pop()
            return res
        while self.stkTail:
            val = self.stkTail.pop()
            self.stkHead.append(val)
        res = self.stkHead[-1]
        self.stkHead.pop()
        return res

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
