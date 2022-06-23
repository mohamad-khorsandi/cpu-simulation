#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "func_lib.h"
#include "control_unit.h"

int count_file_lines(FILE*);

const int mem_sz = 100;
long* mem;

void load_to_mem(char* file_name){
    FILE* bin_fp = fopen(file_name, "r");
    if (bin_fp == NULL){
        printf("%s cannot be openned\n", file_name);
        exit(1);
    }
    int no_lines = count_file_lines(bin_fp);

    mem = malloc(mem_sz * sizeof(long));

    for (int i = 0; i < no_lines; i++){
        fscanf(bin_fp,"%ld", mem + i);
    }

    fclose(bin_fp);
    bin_fp = NULL;
}

int count_file_lines(FILE* fp){
    char c;
    size_t count = 0;

    while(c != EOF){
        c = fgetc(fp);
        if(c == '\n')
            count++;
    }
    rewind(fp);
    return count;
}

void show_mem(){
    int isInDataSeg = 0;
    printf("\ndata memory: ");
    for (int i = 0; i < mem_sz; i++){
        if(isInDataSeg == 1 && mem[i] != 0)
            printf("%d:%ld ", i, mem[i]);

        if(isInDataSeg != 1 && mem[i] == 234881024)
            isInDataSeg = 1;
    }
}

long im_access(int index){
    if(index > mem_sz || index < 0){
        printf("%s", "mem index out of bound");
        exit(1);
    }

    return mem[index];
}

long dm_access(int index){
    if (memRead != 1) return -1000;
    if(index > mem_sz || index < 0){
        printf("%s", "mem index out of bound");
        exit(1);
    }

    return mem[index];
}

void write_to_mem(long data, int index){
    if (memWrite != 1) return;

    if(index > mem_sz || index < 0){
        printf("%s", "mem index out of bound");
        exit(1);
    }

    mem[index] = data;
}
