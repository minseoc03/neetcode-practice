class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.maxHeap, -num)
        a = heapq.heappop(self.maxHeap)
        heapq.heappush(self.minHeap, -a)
        if len(self.minHeap) > len(self.maxHeap):
            b = heapq.heappop(self.minHeap)
            heapq.heappush(self.maxHeap, -b)

    def findMedian(self) -> float:
        if (len(self.minHeap) + len(self.maxHeap)) % 2 == 0:
            return (self.minHeap[0] + -self.maxHeap[0]) / 2
        return -self.maxHeap[0]
        