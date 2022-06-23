#include <stdio.h>
#include "alu.h"
int zero_flg;
long execute_opr(long rs, long rt_imm){
    zero_flg = 0;
    switch(aluOp){
        case ADD:
            return rs + rt_imm;
        break;

        case SUB:
            if(rt_imm == rs) zero_flg = 1;
            return rs - rt_imm;
        break;

        case SLT:
            if (rs < rt_imm)
                return 1;
            else
                return 0;
        break;

        case OR:
            return rs | rt_imm;
        break;

        case NAND:
            return ~(rs & rt_imm);
        break;

        case SL16:
            return rt_imm << 16;
        break;

        default:
            return -1000;
        break;

    }

}
