#include <inttypes.h>

#ifndef PARSE_H
#define PARSE_H

#define reg_fp reg_s0 //s0 is also known as frame pointer

#ifndef BENDIAN

#define RV32I(instr) (!((instr & 0x3) ^0x3))

#define OP_BITMASK(instr) (instr & 0xfe00e07f)
#define OPCODE_BITMASK(instr) (instr & 0x7f)
#define FUNCT3_BITMASK(instr) (instr >> 12 & 0x07)

#define RD_BITFIX(instr) (instr >> 7 & 0x1f)
#define RS1_BITFIX(instr) (instr >> 15 & 0x1f)
#define RS2_BITFIX(instr) (instr >> 20 & 0x1f)
#define IMM_I_BITFIX(instr) (instr >> 20 & 0x1f)
#define IMM_SB_BITFIX(instr) (((instr & 0x80000000) >> 19)\
        + ((instr >> 25) << 10) \
        + ((instr >> 7) & 0x0000001e) \
        + ((instr & 0x00000080) << 4))

#define IMM_U_BITMASK(instr) (instr & 0xfffff000)

#endif

enum __regs {
    reg_zero,   // Hard-wired zero
    reg_ra,     // Return address
    reg_sp,     // Stack Pointer
    reg_gp,     // Global Pointer
    reg_tp,     // Thread Pointer
    reg_t0, t1, t2, //Temporaries
    reg_s0,  // Saved register/frame pointer
    reg_s1,  // Saved register

    //Function args, return vals
    reg_a0, reg_a1, reg_a2, reg_a3, reg_a4, reg_a5, reg_a6, reg_a7, 

    // Saved register
    reg_s2, reg_s3, reg_s4, reg_s5, reg_s6, reg_s7, reg_s8, reg_s9, reg_s10, reg_s11,

    //Temporary registers
    reg_t3, reg_t4, reg_t5, reg_t6
};

enum __instr {
    __lui,
    __jal,
    __beq,
    __bne,
    __blt,
    __bge,
    __bltu,
    __bgeu,
    __sw,
    __lw,
    __addi,
    __xori,
    __ori,
    __andi,
    __add,
    __sub,
    __xor,
    __or,
    __and,
    __sbreak
};

enum __instr_type {
    R_INSTR, I_INSTR, SB_INSTR, U_INSTR
};

struct __r_instr {
    enum __regs rd;
    enum __regs rs1;
    enum __regs rs2;
    enum __instr op;
};

struct __sb_instr {
    enum __regs rs1;
    enum __regs rs2;
    uint32_t imm;
    enum __instr op;
};

struct __u_instr {
    enum __regs rd;
    uint32_t imm;
    enum __instr op;
};

struct __i_instr {
    enum __regs rd;
    enum __regs rs1;
    uint32_t imm;
    enum __instr op;
};

union instruction_info {
    struct __r_instr r;
    struct __sb_instr sb;
    struct __i_instr i;
    struct __u_instr u;
};

typedef struct instruction {
    union instruction_info instr;
    enum __instr_type instr_type;
}instruction;

/////////     OPCODES/OP     /////////
#ifndef BENDIAN
#define LUI_OPCODE      0x00000037
#define JAL_OPCODE      0x0000006f
#define BEQ_OPCODE      0x000000c3
#define BNE_OPCODE      0x000010c3
#define BLT_OPCODE      0x000040c3
#define BGE_OPCODE      0x000050c3
#define BLTU_OPCODE     0x000060c3
#define BGEU_OPCODE     0x000070c3
#define LW_OPCODE       0x00002003
#define SW_OPCODE       0x00002023
#define ADDI_OPCODE     0x00000013
#define XORI_OPCODE     0x00004013
#define ORI_OPCODE      0x00006013
#define ANDI_OPCODE     0x00007013
#define ADD_OPCODE      0x00000033
#define SUB_OPCODE      0x40000033
#define XOR_OPCODE      0x00004033
#define OR_OPCODE       0x00006033
#define AND_OPCODE      0x00007033
#define SBREAK_OPCODE   0x00010073
#endif

//jal
//beq
//bne
//blt
//bge
//bltu
//bgeu
//lw
//sw
//addi
//xori
//ori
//andi
//add
//sub
//xor
//or
//and
//sbreak

char parse_instr(uint32_t *, instruction *);

#endif
