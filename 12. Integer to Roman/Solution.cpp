#include <string>
#include <unordered_map>


class Solution
{
public:
    std::string intToRoman(int num)
    {
        if (NUMERAL_MAP.count(num) > 0)
            return NUMERAL_MAP[num];

        int highest = -1;
        for (const auto& [digit, numeral] : NUMERAL_MAP)
        {
            if ((digit <= num) && (digit > highest))
                highest = digit;
        }

        return NUMERAL_MAP[highest] + intToRoman(num - highest);
    }

private:
    std::unordered_map<int, std::string> NUMERAL_MAP = {
        { 1,    "I"  },
        { 4,    "IV" },
        { 5,    "V"  },
        { 9,    "IX" },
        { 10,   "X"  },
        { 40,   "XL" },
        { 50,   "L"  },
        { 90,   "XC" },
        { 100,  "C"  },
        { 400,  "CD" },
        { 500,  "D"  },
        { 900,  "CM" },
        { 1000, "M"  }
    };
};
