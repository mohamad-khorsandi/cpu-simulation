#include "func_lib.h"

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

long mux(int input0, int input1, int signal){
    if(signal == 1){
        return input1;
    } else if (signal == 0){
        return input0;
    } else
        return -1000;
}
