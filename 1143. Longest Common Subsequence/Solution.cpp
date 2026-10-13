#include <algorithm>
#include <string>
#include <unordered_map>


class Solution
{
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2) noexcept
    {
        std::unordered_map<uint64_t, int> memo;
        return longestCommonSubsequenceImpl(text1, text2, memo);
    }

private:
    static constexpr int longestCommonSubsequenceImpl(const std::string& text1, const std::string& text2,
        std::unordered_map<uint64_t, int>& memo, int i = 0, int j = 0) noexcept
    {
        if (text1 == text2)
            return (int)text1.size();

        if ((i >= text1.size()) || (j >= text2.size()))
            return 0;

        uint64_t key = Hash(i, j);
        if (memo.contains(key))
            return memo.at(key);

        if (text1[i] == text2[j])
            return 1 + longestCommonSubsequenceImpl(text1, text2, memo, i + 1, j + 1);

        int res   = std::max(longestCommonSubsequenceImpl(text1, text2, memo, i + 1, j),
            longestCommonSubsequenceImpl(text1, text2, memo, i, j + 1));
        memo[key] = res;

        return res;
    }

    static constexpr uint64_t Hash(int i, int j) noexcept { return (i ^ 0x997642) | (static_cast<uint64_t>(j) << 32); }
};
