class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i, j = 0, len(heights) - 1
        area = 0
        while i < j:
            area = max(area, (j - i) * min(heights[j], heights[i]))
            if heights[j] < heights[i]:
                j -= 1
            elif heights[j] > heights[i]:
                i += 1
            else:
                i += 1
                j -= 1
        
        return area