int mySqrt(int x)
{
    int res;

    __asm__(
        "addl $1, %1\n\t"
        "movl %1, %0\n\t"
        : "=r"(res)
        : "r"(x)
        : "cc"
    );

    return res;
}
