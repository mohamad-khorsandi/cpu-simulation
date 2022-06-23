#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "control_unit.h"
#include "register_file.h"
#include "func_lib.h"
#include "alu.h"

typedef struct instruction{
    int opcode;
    int rs;
    int rt;
    int rd;
    int offset;
}inst;

void set_inst_fields(long, inst*);
void show(int, int);
void update_stat(int);
void show_stat();

int pc = 0;
const long halt = 234881024;
int used_registers[16];
int no_cycles = 0;
int no_used_reg = 0;
int no_mem_read = 0;
int no_mem_write = 0;

int main(int argc, char **argv){
    if(argc < 2){
         printf("wrong number of inputs");
         exit(1);
    }

    load_to_mem(argv[1]);
    show_mem();

    long dec_inst;
    inst cur_inst;
    while((dec_inst = im_access(pc)) != halt){
        pc = pc + 1;
        set_inst_fields(dec_inst, &cur_inst);
        set_signals(cur_inst.opcode);

        long rs_val = get_regiter(cur_inst.rs);
        long rt_val = get_regiter(cur_inst.rt);

        long secAluSrc = mux(rt_val, cur_inst.offset, aluSrc);

        long aluRes = execute_opr(rs_val, secAluSrc);

        int branch_dest = cur_inst.offset + pc;

        long nextPc = mux(pc, branch_dest, (zero_flg && branch));
        nextPc = mux(nextPc, cur_inst.offset, jump);
        nextPc = mux(nextPc, rs_val, jumpReg);

        write_to_mem(rt_val, aluRes);

        long memRes = dm_access(aluRes);

        long wbData = mux(mux(aluRes, memRes, memToReg), pc, linkReg);

        long destReg = mux(cur_inst.rt, cur_inst.rd, regDst);

        write_to_rf(wbData, destReg);

        show(pc, nextPc);
        pc = nextPc;
        update_stat(destReg);
    }
    show_stat();
    return 0;
}

void set_inst_fields(long dec_inst, inst* cur_inst){
    cur_inst->opcode = bin_slice(dec_inst, 24, 27);
    cur_inst->offset = bin_slice(dec_inst, 0, 15);
    cur_inst->rd = bin_slice(dec_inst, 12, 15);
    cur_inst->rt = bin_slice(dec_inst, 16, 19);
    cur_inst->rs = bin_slice(dec_inst, 20, 23);
}

void show(int pc, int nextPc){
    printf("\n----------------------------------");
    printf("\ninst line:%d",pc);
    show_mem();
    show_rf();
}

void update_stat(int index){
    no_cycles++;
    if (memRead) no_mem_read++;
    if (memWrite) no_mem_write++;
    if (regWrite){
        if (used_registers[index] == 0){
            used_registers[index] = 1;
            no_used_reg++;
        }
    }
}

void show_stat(){
    printf("\n\n total number of cycles: %d", no_cycles);
    printf("\n number of read from memory: %d", no_mem_read);
    printf("\n number of write to memory: %d", no_mem_write);
    printf("\n Percentage of used registers: %f%%\n", (no_used_reg / 16.0)*100);
}
