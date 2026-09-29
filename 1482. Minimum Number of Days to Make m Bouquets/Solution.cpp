#include <algorithm>
#include <cstdint>
#include <vector>


class Solution
{
public:
    constexpr int minDays(std::vector<int>& bloomDay, int m, int k) const noexcept
    {
        const int n = static_cast<int>(bloomDay.size());

        // Not enough flowers
        if (static_cast<uint64_t>(n) < ((uint64_t)k * m))
            return -1;

        int left  = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        return minDaysImpl(bloomDay, m, k, left, right);
    }

private:
    static constexpr int minDaysImpl(std::vector<int>& bloomDay, int m, int k, int left, int right) noexcept
    {
        if (left > right)
            return left;

        const int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid))
            return minDaysImpl(bloomDay, m, k, left, mid - 1);

        return minDaysImpl(bloomDay, m, k, mid + 1, right);
    }

    static constexpr bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int day) noexcept
    {
        int bouquets    = 0;
        int consecutive = 0;

        for (int flower : bloomDay)
        {
            if (flower <= day)
            {
                ++consecutive;
                if (consecutive == k)
                {
                    ++bouquets;
                    consecutive = 0;

                    if (bouquets == m)
                        return true;
                }
            }
            else
                consecutive = 0;
        }

        return false;
    }
};
