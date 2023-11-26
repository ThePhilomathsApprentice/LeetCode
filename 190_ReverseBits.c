#include <stdio.h>
#include <stdint.h>

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
    uint32_t x = 0b00000010100101000001111010011100;
    printf("X=%lu\nreverseX=%lu\n", x, reverseBits_optimised(x));

    uint32_t x2 = 0b11111111111111111111111111111101;
    printf("X2=%lu\nreverseX2=%lu\n", x2, reverseBits_optimised(x2));

    return 0;
}