#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target)
    {
        return search_impl(nums, target, 0, nums.size() - 1);
    }

private:
    int search_impl(std::vector<int>& nums, int target, int left, int right)
    {
        if (left > right)
            return -1;

        const int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            return search_impl(nums, target, left, mid - 1);

        return search_impl(nums, target, mid + 1, right);
    }
};
