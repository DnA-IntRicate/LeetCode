__attribute__((naked)) int mySqrt(int x)
{
    // Parameter x is in edi
    // Return register is eax

    __asm__(
        ".intel_syntax noprefix; \
        push rbp; \
        mov rbp, rsp; \
        sub rsp, 16; \
        \
        \
        xor eax, eax; \
        mov eax, edi; \
        \
        mov rsp, rbp; \
        pop rbp; \
        ret; \
        .att_syntax; \
    ");
}
