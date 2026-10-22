#include <algorithm>
#include <cstdint>
#include <vector>


class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount)
    {
        std::vector<uint64_t> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (const auto& coin : coins)
            for (int i = coin; i < amount + 1; ++i)  // `i` is the Current Amount
                dp[i] = std::min(dp[i], dp[i - coin] + 1);

        return (dp[amount] != INT_MAX) ? static_cast<int>(dp[amount]) : -1;
    }
};
