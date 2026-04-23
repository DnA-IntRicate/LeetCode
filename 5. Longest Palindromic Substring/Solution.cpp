#include <string>


class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.empty())
            return "";

        int start  = 0;
        int maxLen = 1;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            Expand(s, i, i, start, maxLen);
            Expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void Expand(const std::string& s, int left, int right, int& start, int& maxLen)
    {
        while ((left >= 0) && (right < (int)s.size()) && (s[left] == s[right]))
        {
            int len = right - left + 1;
            if (len > maxLen)
            {
                start  = left;
                maxLen = len;
            }

            --left;
            ++right;
        }
    }
};
