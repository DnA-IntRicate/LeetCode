#include <stdbool.h>
#include <stdint.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    size_t num = (size_t)x;
    size_t reversedNum = 0;

    while (num > 0)
    {
        reversedNum = reversedNum * 10 + (num % 10);
        num /= 10;
    }

    return (size_t)x == reversedNum;
}
