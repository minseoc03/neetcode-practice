class Solution:
    def maxArea(self, heights: List[int]) -> int:
        def retHeight(lo, hi):
            if heights[lo] > heights[hi]:
                height = heights[hi]
            else:
                height = heights[lo]
            return height

        lo = 0
        hi = len(heights) - 1
        area = (hi-lo) * retHeight(lo, hi)

        while lo < hi:
            if heights[lo] < heights[hi]:
                lo += 1
            else:
                hi -= 1
            area = max(area, (hi-lo) * retHeight(lo, hi))
        
        return area