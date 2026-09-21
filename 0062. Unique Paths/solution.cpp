#include <algorithm>
#include <cstdint>


class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return CountPaths(m, n);
    }

private:
    // Brute force solution
    constexpr int CountPaths(int row, int col, int m, int n) const noexcept
    {
        // Destination
        if ((row == m - 1) && (col == n - 1))
            return 1;

        // Out of bounds
        if ((row >= m) || (col >= n))
            return 0;

        // Robot only ever has 2 moves, down or right
        return CountPaths(row + 1, col, m, n) + CountPaths(row, col + 1, m, n);
    }

    // Combinatorics
    constexpr int CountPaths(int m, int n) const noexcept
    {
        uint64_t res = 1;

        const int total = m + n - 2;
        const int choose = std::min(m - 1, n - 1);

        for (int i = 1; i <= choose; ++i)
            res = res * (total - choose + i) / i;

        return static_cast<int>(res);
    }
};
