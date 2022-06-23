#include "register_file.h"
#include "control_unit.h"
long registers[16];

int get_regiter(int index){
    if (index < 0 || index > 15){
        printf("%s", "register file index out of bound");
        exit(1);
    }
    return registers[index];
}

void write_to_rf(long data, int index){
    if (regWrite != 1) return;

    if (index < 0 || index > 15){
        printf("%s", "register file index out of bound");
        exit(1);
    }

    if (index == 0){
        printf("register 0 can not be written into");
        exit(1);
    }

    registers[index] = data;
}

void show_rf(){
    printf("\nregisters: ");
    for(int i = 0; i < 16; i++)
        printf("%d:%ld ", i, registers[i]);
}
