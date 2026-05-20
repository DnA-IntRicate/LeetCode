int mySqrt(int x)
{
    if (x <= 0)
        return 0;

    if (x == 1)
        return 1;

    // So we have to binary search... Nice

    int left  = 0;
    int right = x;
    int res   = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid)
        {
            res  = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return res;
}
