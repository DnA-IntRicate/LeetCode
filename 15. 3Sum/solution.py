class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        res = []

        for i in range(len(nums) - 2):
            # Skip duplicates for first number
            if (i > 0) and (nums[i] == nums[i - 1]):
                continue

            if nums[i] > 0:
                break

            left = i + 1
            right = len(nums) - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    res.append([nums[i], nums[left], nums[right]])

                    left += 1
                    right -= 1

                    # Skip duplicates
                    while (left < right) and (nums[left] == nums[left - 1]):
                        left += 1

                    while (left < right) and (nums[right] == nums[right + 1]):
                        right -= 1

        return res
