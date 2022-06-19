#include <stdio.h>
#define x -1
typedef enum opr{
    ADD, SUB, SLT, OR,NAND, SL16
}opr;

typedef enum inst{
    add=0, sub=1, slt=2, or=3, nand=4, addi=5 , slti=6, ori=7, lui=8, lw=9, sw=10, beq=11, jalr=12, j=13, halt=14
}inst;

int regDst;
int extOP;
int aluSrc;
opr aluOp;
int memRead;
int memWrite;
int branch;
int jump;
int memToReg;
int linkReg;
int jumpReg;
int regWrite;

void set_signals(int opcode){
    switch(opcode){
    //R Type----------------------------------
        case add:
            setter(1,x,0,ADD,0,0,0,0,0,0,0,1);
        break;

        case sub:
            setter(1,x,0,SUB,0,0,0,0,0,0,0,1);
        break;

        case slt:
            setter(1,x,0,SLT,0,0,0,0,0,0,0,1);
        break;

        case or:
            setter(1,x,0,OR,0,0,0,0,0,0,0,1);
        break;

        case nand:
            setter(1,x,0,NAND,0,0,0,0,0,0,0,1);
        break;
    //I Type----------------------------------
        case addi:
            setter(0,1,1,ADD,0,0,0,0,0,0,0,1);
        break;

        case slti:
            setter(0,1,1,SLT,0,0,0,0,0,0,0,1);
        break;

        case ori:
            setter(0,0,1,OR,0,0,0,0,0,0,0,1);
        break;

        case lui:
            setter(0,0,1,SL16,0,0,0,0,0,0,0,1);
        break;

        case lw:
            setter(0,1,1,ADD,1,0,0,0,1,0,0,1);
        break;

        case sw:
            setter(0,1,1,ADD,0,1,0,0,x,0,0,0);
        break;

        case beq:
            setter(x,1,1,SUB,0,0,1,0,x,0,0,0);
        break;

        case jalr:
            setter(0,x,x,x,0,0,x,x,x,1,1,1);
        break;
    //R Type----------------------------------
        case j:
            setter(x,x,x,x,0,0,x,1,x,x,0,0);
        break;
    }
}

void setter(int a, int b, int c, opr d, int e, int f, int g, int h, int i, int j, int k, int l){
    regDst = a;
    extOP = b;
    aluSrc = c;
    aluOp = d;
    memRead = e;
    memWrite = f;
    branch = g;
    jump = h;
    memToReg = i;
    linkReg = j;
    jumpReg = k;
    regWrite = l;
}


