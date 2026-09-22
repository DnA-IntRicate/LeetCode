#include <vector>


class Solution
{
public:
    int subsetXORSum(std::vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        const size_t n           = nums.size();
        const size_t subsetCount = 1 << n;

        std::vector<std::vector<int>> subsets(subsetCount);
        int sum = 0;

        for (size_t mask = 0; mask < subsetCount; ++mask)
        {
            int xorSum = 0;
            for (size_t i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                    xorSum ^= nums[i];
            }

            sum += xorSum;
        }

        return sum;
    }
};
