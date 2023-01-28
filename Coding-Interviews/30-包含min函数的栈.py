class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # data 和 minData 是一一对应的关系
        self.data = []
        self.minData = []

    def push(self, x: int) -> None:
        if not self.data or x < self.min():
            self.minData.append(x)
        else:
            self.minData.append(self.minData(-1))
        self.data.append(x)

    def pop(self) -> None:
        self.data.pop()
        self.minData.pop()

    def top(self) -> int:
        return self.data[-1]

    def min(self) -> int:
        return self.minData[-1]

        # Your MinStack object will be instantiated and called as such:
        # obj = MinStack()
        # obj.push(x)
        # obj.pop()
        # param_3 = obj.top()
        # param_4 = obj.min()
