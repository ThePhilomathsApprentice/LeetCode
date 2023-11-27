#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#define NUM_TO_TEST 5

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    int *array = (int *)malloc((n + 1) * sizeof(int));

    array[0] = 0;
    *returnSize = n + 1;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = array[i >> 1];
        }
        else
        {
            array[i] = array[i >> 1] + 1;
        }
    }

    return array;
}

int main()
{
    struct timespec begin;
    struct timespec end;

    int size;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    int *count = countBits(NUM_TO_TEST, &size);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent_ns = (end.tv_nsec - begin.tv_nsec);

    for (int i = 0; i < size; i++)
    {
        printf("arr[%i]=%i.\n\n", i, count[i]);
    }
    printf("Time taken = (%lf ns)\n\n", time_spent_ns);

    free(count);
}