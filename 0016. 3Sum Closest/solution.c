#include <math.h>


void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j   = i - 1;

        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j          = j - 1;
        }

        arr[j + 1] = key;
    }
}

/**
 * Given a list of numbers, nums
 * We need to find 3 integers at distinct indices in nums
 * Such that their sum either equals or is the closest to 'target'
 */
int threeSumClosest(int* nums, int numsSize, int target)
{
    insertion_sort(nums, numsSize);
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; ++i)
    {
        int left  = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int curr_sum = nums[i] + nums[left] + nums[right];
            if (abs(curr_sum - target) < abs(closest - target))
                closest = curr_sum;

            if (curr_sum < target)
                left += 1;
            else if (curr_sum > target)
                right -= 1;
            else
                return curr_sum;
        }
    }

    return closest;
}
