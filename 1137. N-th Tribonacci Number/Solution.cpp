#include <unordered_map>


class Solution
{
public:
    int tribonacci(int n) const noexcept
    {
        std::unordered_map<int, int> memo;
        return tribonacciImpl(n, memo);
    }

private:
    static constexpr int tribonacciImpl(int n, std::unordered_map<int, int>& memo) noexcept
    {
        if (n <= 0)
            return 0;

        if (n == 1)
            return 1;

        if (memo.contains(n))
            return memo.at(n);

        int res = tribonacciImpl(n - 1, memo) + tribonacciImpl(n - 2, memo) + tribonacciImpl(n - 3, memo);
        memo[n] = res;

        return res;
    }
};
