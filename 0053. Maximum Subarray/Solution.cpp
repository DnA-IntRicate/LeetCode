#include <algorithm>
#include <ranges>
#include <vector>


class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        return Kadane(nums);
    }

private:
    static constexpr int Kadane(const std::vector<int>& nums) noexcept
    {
        if (nums.empty())
            return 0;

        int globalMax = nums[0];
        int currMax = globalMax;

        for (const auto& num : nums | std::views::drop(1))
        {
            currMax   = std::max(num, num + currMax);
            globalMax = std::max(currMax, globalMax);
        }

        return globalMax;
    }
};
