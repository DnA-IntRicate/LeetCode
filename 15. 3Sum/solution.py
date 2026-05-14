class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res: list[list[int]] = []
        found: list[list[int]] = []

        for i in range(len(nums)):
            for j in range(i, len(nums)):
                for k in range(j, len(nums)):
                    num_i, num_j, num_k = nums[i], nums[j], nums[k]
                    if (i != j != k) and (num_i + num_j + num_k == 0):
                        triplet = [num_i, num_j, num_k]
                        triplet_sorted = sorted(triplet)
                        if triplet_sorted in found:
                            continue

                        res.append(triplet)
                        found.append(triplet_sorted)

        return res


# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation:
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
