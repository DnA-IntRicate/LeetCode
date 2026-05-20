__attribute__((naked)) int mySqrt(int x)
{
    // Param x is in edi
    // Return register is eax

    __asm__(
        ".intel_syntax noprefix\n"

        // xmm0 = (double)x
        "cvtsi2sd xmm0, edi\n"

        // xmm0 = sqrt(xmm0)
        "sqrtsd xmm0, xmm0\n"

        // convert back to int (truncate toward 0)
        "cvttsd2si eax, xmm0\n"

        "ret\n"
        ".att_syntax\n");
}
