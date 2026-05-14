#include <string.h>
#include <stdlib.h>


char* longestCommonPrefix(char** strs, int strsSize)
{
    if (!strs || (strsSize == 0))
        return "";

    for (int i = 0; i < strlen(strs[0]); ++i)
    {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; ++j)
        {
            if ((i >= strlen(strs[j])) || (strs[j][i] != c))
            {
                char* res = malloc(i + 1);
                strncpy(res, strs[0], i);
                res[i] = '\0';

                return res;
            }
        }
    }

    return strs[0];
}
