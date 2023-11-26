#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t reverse_n = 0;
    for (int i = 0; i < 32; i++)
    {

        reverse_n <<= 1;

        if ((n & 1) == 1)
        {
            reverse_n++;
        }

        n >>= 1;
    }
    return reverse_n;
}

uint32_t reverseBits_optimised(uint32_t n)
{
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int main()
{
    struct timespec begin;
    struct timespec end;

    printf("UnOptimised:\n");
    uint32_t x1 = 0b00000010100101000001111010011100;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    uint32_t rev_x1 = reverseBits(x1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent_ns = (end.tv_nsec - begin.tv_nsec);

    printf("X=%lu\nreverseX=%lu (%lf ns)\n\n", x1, rev_x1, time_spent_ns);

    uint32_t x2 = 0b11111111111111111111111111111101;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    uint32_t rev_x2 = reverseBits(x2);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    time_spent_ns = (end.tv_nsec - begin.tv_nsec);
    printf("X2=%lu\nreverseX2=%lu (%lf ns)\n\n", x2, rev_x2, time_spent_ns);

    printf("Optimised:\n");
    uint32_t x3 = 0b00000010100101000001111010011100;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    uint32_t rev_x3 = reverseBits_optimised(x3);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    time_spent_ns = (end.tv_nsec - begin.tv_nsec);
    printf("X3=%lu\nreverseX3=%lu (%lf ns)\n\n", x3, rev_x3, time_spent_ns);

    uint32_t x4 = 0b11111111111111111111111111111101;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    uint32_t rev_x4 = reverseBits_optimised(x4);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    time_spent_ns = (end.tv_nsec - begin.tv_nsec);
    printf("X4=%lu\nreverseX4=%lu (%lf ns)\n\n", x4, rev_x4, time_spent_ns);

    return 0;
}