#include <algorithm>
#include <cctype>
#include <string>


class Solution
{
public:
    int myAtoi(std::string s)
    {
        int i = 0;
        int n = s.size();

        while ((i < n) && std::isspace((unsigned char)s[i]))
            ++i;

        int sign = 1;
        if ((i < n) && ((s[i] == '+') || (s[i] == '-')))
        {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        int res = 0;
        while ((i < n) && std::isdigit((unsigned char)s[i]))
        {
            int digit = s[i] - '0';

            // Handle overflow
            if (res > (INT_MAX - digit) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN;

            res = res * 10 + digit;
            ++i;
        }

        return res * sign;
    }
};
