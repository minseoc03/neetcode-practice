import heapq
class MedianFinder:

    def __init__(self):
        self.hq = []
        heapq.heapify(self.hq)

    def addNum(self, num: int) -> None:
        heapq.heappush(self.hq, num)

    def findMedian(self) -> float:
        n = len(self.hq)
        tmp = heapq.nlargest(n//2 + 1, self.hq)
        if n % 2 == 0:
            return (tmp[-1] + tmp[-2]) / 2
        return tmp[-1]