#include <stdio.h>
#include <stdlib.h>
#include "func_lib.h"

int count_file_lines(FILE*);

int mem_sz;
long* mem;

void load_to_mem(char* file_name){
    FILE* bin_fp = fopen(file_name, "r");
    if (bin_fp == NULL){
        printf("%s cannot be openned\n", file_name);
        exit(1);
    }
    mem_sz = count_file_lines(bin_fp);

    mem = malloc(mem_sz * sizeof(long));

    for (int i = 0; i < mem_sz; i++){
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
    for (int i = 0; i < mem_sz; i++){
        printf("%ld\n", mem[i]);
    }
}

long mem_access(int index){
    if(index > mem_sz || index < 0){
        printf("%s", "mem index out of bound");
        exit(1);
    }

    return mem[index];
}
