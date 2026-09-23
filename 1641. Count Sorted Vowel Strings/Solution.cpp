#include <utility>


class Solution
{
public:
    constexpr int countVowelStrings(int n) const noexcept
    {
        return Comb(n + 4, 4);
    }

private:
    constexpr int Comb(int n, int r) const noexcept
    {
        if (r > n)
            return 0;

        r = std::min(r, n - r);

        int result = 1;
        for (int i = 1; i <= r; ++i)
            result = result * (n - r + i) / i;

        return result;
    }
};
