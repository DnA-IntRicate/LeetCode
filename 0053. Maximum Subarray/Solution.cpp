#include <algorithm>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>


// Hash function for my pair
namespace std
{
    template<>
    struct hash<std::pair<int, int>>
    {
        std::size_t operator()(const std::pair<int, int>& pair) const noexcept
        {
            const auto& [left, right] = pair;

            std::size_t h1 = std::hash<int>{}(left);
            std::size_t h2 = std::hash<int>{}(right);

            return h1 | h2;
        }
    };
}

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        std::unordered_map<std::pair<int, int>, int> memo;
        return maxSubArrayImpl(nums, memo, 0, nums.size() - 1);
    }

private:
    static constexpr int maxSubArrayImpl(
        const std::vector<int>& nums,
        std::unordered_map<std::pair<int, int>, int>& memo,
        int left,
        int right
    ) noexcept
    {
        if (nums.empty())
            return 0;

        if (nums.size() == 1)
            return nums[0];

        if (left == right)
            return nums[left];

        const auto key = std::make_pair(left, right);
        if (memo.contains(key))
            return memo.at(key);

        auto sliced = nums | std::views::drop(left) | std::views::take(right - left + 1);
        int sum = std::reduce(sliced.begin(), sliced.end());

        int res = std::max({
            sum,
            maxSubArrayImpl(nums, memo, left + 1, right),
            maxSubArrayImpl(nums, memo, left, right - 1)
        });
        memo[key] = res;

        return res;
    }
};
