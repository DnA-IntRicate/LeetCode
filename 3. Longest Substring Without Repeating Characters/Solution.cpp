#include <algorithm>
#include <unordered_map>
#include <string>


class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> seen;
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            char c = s[right];
            if (seen.contains(c) && seen[c] >= left)
                left = seen[c] + 1;

            seen[c] = right;
            res = std::max(res, right - left + 1);
        }

        return res;
    }
};
