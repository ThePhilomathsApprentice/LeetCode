#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>


#define START 10
#define GOAL   7

int hammingWeight(uint32_t n) {
    int hammingweight=0;
    while(n){
        if(n&1 == 1){
            hammingweight++;
        }

        n >>= 1;

    }
    return hammingweight;

}

int minBitFlips(int start, int goal) {
    int XOR = start ^ goal;
    return hammingWeight(XOR);

}


int main(){
    struct timespec begin;
    struct timespec end;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin);
    int minFlips =minBitFlips(START,GOAL);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double time_spent_ns = (end.tv_nsec - begin.tv_nsec);

    printf("Minimum number of flips required to convert %d to %d is %d (%lf ns).\n",
            START,
            GOAL,
            minFlips,
            time_spent_ns);
}