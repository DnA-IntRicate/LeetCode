#include <unordered_map>


class Solution
{
public:
    int climbStairs(int n) noexcept
    {
        std::unordered_map<int, int> memo;
        return climbStairsImpl(n, memo);
    }

private:
    static constexpr int climbStairsImpl(int n, std::unordered_map<int, int>& memo) noexcept
    {
        if (memo.contains(n))
            return memo.at(n);

        if (n == 0)
            return 1;

        if (n < 0)
            return 0;

        int res = climbStairsImpl(n - 1, memo) + climbStairsImpl(n - 2, memo);
        memo[n] = res;

        return res;
    }
};
