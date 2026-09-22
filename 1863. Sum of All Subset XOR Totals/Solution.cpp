#include <vector>


class Solution
{
public:
    int subsetXORSum(std::vector<int>& nums)
    {
        int bits = 0;
        for (int num : nums)
            bits |= num;

        return bits * (1 << (nums.size() - 1));
    }
};
