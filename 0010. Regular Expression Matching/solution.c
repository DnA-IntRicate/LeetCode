#include <stdbool.h>
#include <string.h>


bool empty(char* s)
{
    return strlen(s) == 0;
}

char* cut(char* s, int start)
{
    return s + start;
}

bool isMatch(char* s, char* p)
{
    if (empty(p))
        return empty(s);

    bool first_match = !empty(s) && ((p[0] == s[0]) || (p[0] == '.'));
    if ((strlen(p) >= 2) && (p[1] == '*'))
    {
        return isMatch(s, cut(p, 2)) ||
            (first_match && isMatch(cut(s, 1), p));
    }

    return first_match && isMatch(cut(s, 1), cut(p, 1));
}
