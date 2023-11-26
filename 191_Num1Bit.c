#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

int hammingWeight(uint32_t n)
{
    int hammingweight = 0;
    while (n)
    {
        if (n & 1 == 1)
        {
            hammingweight++;
        }

        n >>= 1;
    }
    return hammingweight;
}

int main()
{
    struct timespec begin;
    struct timespec end;

    int n = 9;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    int hamming = hammingWeight(n);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent_ns = (end.tv_nsec - begin.tv_nsec);

    printf("hammingWeight(%d)=%d (%lf ns)\n\n", n, hamming, time_spent_ns);

    int n2 = 4294967294;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    int hamming2 = hammingWeight(n2);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    time_spent_ns = (end.tv_nsec - begin.tv_nsec);

    printf("hammingWeight(%d)=%d (%lf ns)\n\n", n2, hamming2, time_spent_ns);

    return 0;
}