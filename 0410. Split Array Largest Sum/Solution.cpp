#include <algorithm>
#include <cstdint>
#include <ranges>
#include <vector>

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
//
// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

class Solution
{
public:
    int splitArray(std::vector<int>& nums, int k) const noexcept
    {
        int left  = *std::ranges::max_element(nums);
        int right = Sum(nums);

        return splitArrayImpl(nums, k, left, right);
    }

private:
    static int splitArrayImpl(std::vector<int>& nums, int k, int left, int right) noexcept
    {
        if (left >= right)
            return left;

        const int mid = left + (right - left) / 2;
        if (CanSplit(nums, k, mid))
            return splitArrayImpl(nums, k, left, mid);

        return splitArrayImpl(nums, k, mid + 1, right);
    }

    static bool CanSplit(const std::vector<int>& nums, int k, int maxSum) noexcept
    {
        int subArrays  = 1;
        int currentSum = 0;

        for (const auto& n : nums)
        {
            if (currentSum + n > maxSum)
            {
                ++subArrays;
                currentSum = n;

                if (subArrays > k)
                    return false;
            }
            else
                currentSum += n;
        }

        return true;
    }

    static constexpr int Sum(const std::vector<int>& nums) noexcept
    {
        int res = 0;
        for (const auto& i : nums)
            res += i;

        return res;
    }
};
