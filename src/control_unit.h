#ifndef CONTROL_UNIT_H_INCLUDED
#define CONTROL_UNIT_H_INCLUDED
typedef enum opr{
    ADD, SUB, SLT, OR,NAND, SL16
}opr;

void set_signals(int);

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

#endif // CONTROL_UNIT_H_INCLUDED
