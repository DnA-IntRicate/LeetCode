#include <algorithm>
#include <unordered_map>
#include <vector>


class Solution
{
public:
    int minCostClimbingStairs(std::vector<int>& cost) const noexcept
    {
        std::unordered_map<int, int> memo;
        return std::min(minCostClimbingStairsImpl(cost, 0, memo), minCostClimbingStairsImpl(cost, 1, memo));
    }

private:
    static constexpr int minCostClimbingStairsImpl(std::vector<int>& cost, int i, std::unordered_map<int, int>& memo) noexcept
    {
        if (i >= cost.size())
            return 0;

        if (memo.contains(i))
            return memo.at(i);

        int res1 = minCostClimbingStairsImpl(cost, i + 1, memo);
        int res2 = minCostClimbingStairsImpl(cost, i + 2, memo);
        int res = cost[i] + std::min(res1, res2);
        memo[i] = res;

        return res;
    }
};
