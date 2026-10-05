#include <algorithm>
#include <unordered_map>
#include <vector>


class Solution
{
public:
    int rob(std::vector<int>& nums) const noexcept
    {
        std::unordered_map<int, int> memo;
        return std::max(robImpl(nums, memo, 0), robImpl(nums, memo, 1));
    }

private:
    static constexpr int robImpl(const std::vector<int>& nums, std::unordered_map<int, int>& memo, int i) noexcept
    {
        if (i >= nums.size())
            return 0;

        if (memo.contains(i))
            return memo.at(i);

        int res = nums[i] + std::max(robImpl(nums, memo, i + 2), robImpl(nums, memo, i + 3));
        memo[i] = res;

        return res;
    }
};
