#include <algorithm>
#include <vector>
#include <unordered_map>


class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        // Value, Index
        std::unordered_map<int, int> seen;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int complement = target - num;
            
            if (seen.contains(complement))
                return { seen[complement], (int)i };

            seen[num] = i;
        }
        
        return {};
    }
};
