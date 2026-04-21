#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                int* res = (int*)malloc(sizeof(int) * 2);
                res[0] = i; res[1] = j;

                return res;
            }
        }
    }

    *returnSize = 0;
    return (void*)0;
}
