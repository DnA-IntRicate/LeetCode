#include <memory.h>
#include <stdlib.h>


#define BLOCK_SIZE 16

int fib_impl(int n, int** memo, int* mem_length);

int fib(int n)
{
    int mem_length = BLOCK_SIZE;
    int* memo = (int*)malloc(mem_length * sizeof(int));
    memset(memo, -1, mem_length * sizeof(int));

    int res = fib_impl(n, &memo, &mem_length);
    free(memo);

    return res;
}

int fib_impl(int n, int** memo, int* mem_length)
{
    if (n <= 1)
        return n;

    // Resize memo if needed
    while (n >= *mem_length)
    {
        int old_length = *mem_length;
        *mem_length += BLOCK_SIZE;

        int* new_memo = realloc(*memo, *mem_length * sizeof(int));
        if (!new_memo)
            exit(EXIT_FAILURE);

        *memo = new_memo;
        memset(*memo + old_length, -1, BLOCK_SIZE * sizeof(int));
    }

    if ((*memo)[n] != -1)
        return (*memo)[n];

    (*memo)[n] = fib_impl(n - 1, memo, mem_length) + fib_impl(n - 2, memo, mem_length);
    return (*memo)[n];
}
