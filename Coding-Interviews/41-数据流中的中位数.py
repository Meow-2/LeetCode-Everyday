import heapq


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.less = []
        self.greater = []

    def addNum(self, num: int) -> None:
        if len(self.less) == len(self.greater):
            heapq.heappush(self.less, (-num, num))
            heapq.heappush(self.greater, heapq.heappop(self.less)[1])
        else:
            heapq.heappush(self.greater, num)
            temp = heapq.heappop(self.greater)
            heapq.heappush(self.less, (-temp, temp))

    def findMedian(self) -> float:
        if (len(self.less) + len(self.greater)) % 2:
            return self.greater[0]
        else:
            return (self.less[0][1] + self.greater[0])/2

        # Your MedianFinder object will be instantiated and called as such:
        # obj = MedianFinder()
        # obj.addNum(num)
        # param_2 = obj.findMedian()
