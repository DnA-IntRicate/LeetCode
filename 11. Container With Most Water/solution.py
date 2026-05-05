from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        res = 0

        while l < r:
            h = min(height[l], height[r])
            w = r - l
            res = max(res, h * w)

            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return res

# Brute force solution: O(n^2)
# class Solution:
#     def maxArea(self, height: List[int]) -> int:
#         res = 0
#         for i in range(len(height)):
#             for j in range(i + 1, len(height)):
#                 w = j - i
#                 h = min(height[i], height[j])
#
#                 area = h * w
#                 res = max(res, area)
#
#         return res
