#include "func_lib.h"
#include <math.h>

long bin_slice(long num, int s, int e){
    num = num % pow2(e + 1);
    num = num / pow2(s);
    return num;
}

long pow2(int pow){
    long ans = 1;
    for(int i = 0; i < pow; i++){
        ans *= 2;
    }
    return ans;
}
