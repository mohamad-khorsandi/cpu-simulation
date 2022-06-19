#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "control_unit.h"

int pc = 0;
const long halt = 234881024;

int main(int argc, char **argv){
    if(argc < 2){
         printf("wrong number of inputs");
         exit(1);
    }

    load_to_mem(argv[1]);
    show_mem();

    long inst;
    while((inst = mem_access(pc)) != halt){
        pc = pc + 1;
        set_signals(bin_slice(inst, 24, 27));
    }
    return 0;
}
