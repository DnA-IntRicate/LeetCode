#include <string.h>
#include <stdlib.h>


char* intToRoman(int num)
{
    // Roman numerals have a tiny fixed range:
    // 1 <= num <= 3999

    // Digit lookup tables
    const const char* THOUSANDS[] = { "", "M", "MM", "MMM" };
    const const char* HUNDREDS[]  = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    const const char* TENS[]      = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    const const char* ONES[]      = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

    // Max length is 15 chars
    char* res = (char*)malloc(16 * sizeof(char));
    (void)strcpy(res, THOUSANDS[num / 1000]);
    (void)strcat(res, HUNDREDS[(num % 1000) / 100]);
    (void)strcat(res, TENS[(num % 100) / 10]);
    (void)strcat(res, ONES[num % 10]);

    return res;
}
