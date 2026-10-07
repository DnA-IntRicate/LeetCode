#include <algorithm>
#include <unordered_map>
#include <vector>


class Solution
{
public:
    int rob(std::vector<int>& nums) const noexcept
    {
        if (nums.size() == 1)
            return nums.front();

        std::unordered_map<int, int> memo1;
        std::unordered_map<int, int> memo2;

        return std::max(
            robImpl(nums, memo1, 0, nums.size() - 2),
            robImpl(nums, memo2, 1, nums.size() - 1)
        );
    }

private:
    static constexpr int robImpl(const std::vector<int>& nums, std::unordered_map<int, int>& memo, int i, int end) noexcept
    {
        if (i > end)
            return 0;

        if (memo.contains(i))
            return memo.at(i);

        int res = std::max(nums[i] + robImpl(nums, memo, i + 2, end), robImpl(nums, memo, i + 1, end));
        memo[i] = res;

        return res;
    }
};
