
#ifndef PARSE_H
#define PARSE_H

#define reg_fp reg_s0 //s0 is also known as frame pointer
#define RV32I(instr) (!((instr & 0x3) ^0x3))
#define OPCODE_BITMASK(instr) (instr & 0x7f)
#define FUNCT3_BITMASK(instr) (instr >> 12 & 0x07)

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


struct __r_instr {
    enum __regs rd;
    enum __regs rs1;
    enum __regs rs2;
    enum __instr inst;
};

struct __sb_instr {
    enum __regs rs1;
    enum __regs rs2;
    long int unsigned imm;
    enum __instr inst;
};

struct __i_instr {
    enum __regs rd;
    enum __regs src1;
    long int unsigned imm;
    enum __instr inst;
};

typedef union instruction {
    struct __r_instr r_instr;
    struct __sb_instr sb_instr;
    struct __i_instr i_instr;
}instruction;


/////////     OPCODES     /////////
#define LUI_OPCODE      0x0037
#define JAL_OPCODE      0x006f

#define BRANCH_OPCODE   0x00c3
#define BEQ_OPCODE      0x00c3
#define BNE_OPCODE      0x00c3
#define BLT_OPCODE      0x00c3
#define BGE_OPCODE      0x00c3
#define BLTU_OPCODE     0x00c3
#define BGEU_OPCODE     0x00c3
                              
#define LW_OPCODE       0x0003
#define SW_OPCODE       0x0023
                              
#define IMM_OPCODE      0x0013
#define ADDI_OPCODE     0x0013
#define XORI_OPCODE     0x0013
#define ORI_OPCODE      0x0013
#define ANDI_OPCODE     0x0013
                              
#define REG_OPCODE      0x0033
#define ADD_OPCODE      0x0033
#define SUB_OPCODE      0x0033
#define XOR_OPCODE      0x0033
#define OR_OPCODE       0x0033
#define AND_OPCODE      0x0033
                              
#define SBREAK_OPCODE   0x0073



//////////      FUNCT3's     ////////
#define jal_FUNCT3      0x0000
#define beq_FUNCT3      0x0000
#define bne_FUNCT3      0x1000
#define blt_FUNCT3      0x4000
#define bge_FUNCT3      0x5000
#define bltu_FUNCT3     0x6000
#define bgeu_FUNCT3     0x7000
#define lw_FUNCT3       0x2000
#define sw_FUNCT3       0x2000
#define addi_FUNCT3     0x0000
#define xori_FUNCT3     0x4000
#define ori_FUNCT3      0x6000
#define andi_FUNCT3     0x7000
#define add_FUNCT3      0x0000
#define sub_FUNCT3      0x0000
#define xor_FUNCT3      0x4000
#define or_FUNCT3       0x6000
#define and_FUNCT3      0x7000
#define sbreak _FUNCT3  0x0000

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

#endif
