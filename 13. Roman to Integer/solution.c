#include <string.h>


int numeral_to_int(char numeral)
{
    switch (numeral)
    {
        case 'I':   return 1;
        case 'V':   return 5;
        case 'X':   return 10;
        case 'L':   return 50;
        case 'C':   return 100;
        case 'D':   return 500;
        case 'M':   return 1000;
    }

    return 0;
}

int romanToInt(char* s)
{
    if (strlen(s) == 0)
        return 0;

    if (strlen(s) == 1)
        return numeral_to_int(s[0]);

    int num0 = numeral_to_int(s[0]);
    int num1 = numeral_to_int(s[1]);
    if (num0 < num1)
        return (num1 - num0) + romanToInt(s + 2);

    return numeral_to_int(s[0]) + romanToInt(++s);
}
