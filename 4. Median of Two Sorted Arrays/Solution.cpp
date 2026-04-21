#include <algorithm>
#include <vector>
#include <string>
#include <optional>


class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> combined;
        size_t longestLen = std::max(nums1.size(), nums2.size());

        for (size_t i = 0; i < longestLen; ++i)
        {
            std::optional<int> a = (nums1.size() > i) ? std::make_optional(nums1[i]) : std::nullopt;
            std::optional<int> b = (nums2.size() > i) ? std::make_optional(nums2[i]) : std::nullopt;

            if (a.has_value() && b.has_value())
            {
                int valA = a.value();
                int valB = b.value();

                if (valA > valB)
                {
                    combined.emplace_back(valB);
                    combined.emplace_back(valA);
                }
                else
                {
                    combined.emplace_back(valA);
                    combined.emplace_back(valB);
                }
            }
            else
                combined.emplace_back((a.has_value()) ? a.value() : b.value());
        }

        size_t combinedSize = combined.size();

        if (combinedSize % 2 == 0) // Even length
            return combined[(combinedSize / 2)] + combined[(combinedSize / 2) + 1] / 2.0;

        return (double)combined[(combinedSize - 1) / 2];
    }
};
