###python Solution 1:
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store=[] 

    def addNum(self, num: int) -> None:
        self.store.append(num)

    def findMedian(self) -> float:
        store=sorted(self.store)
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]
        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()



###  Python Solution 2:
class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.store=[] 
    
    def insertSort(self,arr):
        for i in range(1,len(arr)):
            j = i-1
            key = arr[i]
            while j >= 0:
                if arr[j] > key:
                    arr[j+1] = arr[j]
                    arr[j] = key
                j -= 1
        return arr
    
    def addNum(self, num: int) -> None:
        self.store.append(num)
        self.store = self.insertSort(self.store)

    def findMedian(self) -> float:
        n = len(self.store)
        if n%2==0:
            return (self.store[n//2]+self.store[n//2-1])/2.0
        else:
            return self.store[n//2]
        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


### Python Solution 3:
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.count = 0
        self.max_heap = []
        self.min_heap = []

    def addNum(self, num: int) -> None:
        # 因为 Python 中的堆默认是小顶堆，所以要传入一个相反数，
        # 才能模拟出大顶堆的效果
        if self.count % 2 == 0:
            heapq.heappush(self.max_heap, -num)
            max_heap_top = heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap,-max_heap_top)
        else:
            heapq.heappush(self.min_heap, num)
            min_heap_top = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap,-min_heap_top)
        self.count+=1
    def findMedian(self) -> float:
        if self.count % 2 == 0:
            return (self.min_heap[0] - self.max_heap[0])/2.0
        else:
            return self.min_heap[0]      


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
