int maxArea(int* height, int heightSize)
{
    int l = 0;
    int r = heightSize - 1;
    int res = 0;

    while (l < r)
    {
        int h = (height[l] < height[r]) ? height[l] : height[r];
        int w = r - l;
        res = (res > h * w) ? res : h * w;

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return res;
}
