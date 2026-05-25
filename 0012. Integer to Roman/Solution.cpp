#include <string>


class Solution
{
public:
    std::string intToRoman(int num)
    {
        // Roman numerals have a tiny fixed range:
        // 1 <= num <= 3999

        // Digit lookup tables
        static const std::string THOUSANDS[] = { "", "M", "MM", "MMM" };
        static const std::string HUNDREDS[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        static const std::string TENS[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        static const std::string ONES[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

        return THOUSANDS[num / 1000] + HUNDREDS[(num % 1000) / 100] + TENS[(num % 100) / 10] + ONES[num % 10];
    }
};
