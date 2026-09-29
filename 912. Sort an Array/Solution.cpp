#include <algorithm>
#include <cstdint>
#include <vector>


class Solution
{
public:
    std::vector<int> sortArray(std::vector<int>& nums) const noexcept
    {
        if (!nums.empty())
            sortArrayImpl(nums, 0, nums.size() - 1);

        return nums;
    }

private:
    static void sortArrayImpl(std::vector<int>& nums, uint64_t left, uint64_t right) noexcept
    {
        if (left >= right)
            return;

        const uint64_t mid = left + (right - left) / 2;

        sortArrayImpl(nums, left, mid);
        sortArrayImpl(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }

    static void Merge(std::vector<int>& nums, uint64_t left, uint64_t mid, uint64_t right) noexcept
    {
        std::vector<int> merged;
        merged.reserve(right - left + 1);

        size_t i = left;
        size_t j = mid + 1;

        while ((i <= mid) && (j <= right))
        {
            if (nums[i] <= nums[j])
                merged.push_back(nums[i++]);
            else
                merged.push_back(nums[j++]);
        }

        while (i <= mid)
            merged.push_back(nums[i++]);

        while (j <= right)
            merged.push_back(nums[j++]);

        std::copy(merged.begin(), merged.end(), nums.begin() + left);
    }
};
