#ifdef DEBUG
#include <stdio.h>
#endif
#include <inttypes.h>

#include "parse.h"
#include "defs.h"

// Takes a pointer to the instruction to parse and prints the Assembly
// TODO: Turn int into an intermediate instruction
char parse_instr(uint32_t *instr_ptr, instruction *ret_instr) {
    uint32_t instr = *instr_ptr;
    uint32_t op = OP_BITMASK(*instr_ptr);
    uint32_t opcode = OPCODE_BITMASK(*instr_ptr);
    
    // Test if the first two bits to assert RV32I
    if (!RV32I(instr))
        goto badop;
    
    switch(op) {
        case BEQ_OPCODE:
            break;
        case BNE_OPCODE:
            break;
        case BLT_OPCODE:
            break;
        case BGE_OPCODE:
            break;
        case BLTU_OPCODE:
            break;
        case BGEU_OPCODE:
            break;
        case SW_OPCODE:
            break;
        case LW_OPCODE:
            ret_instr->instr_type = I_INSTR;
            break;
        case ADDI_OPCODE:
            break;
        case XORI_OPCODE:
            break;
        case ORI_OPCODE:
            break;
        case ANDI_OPCODE:
            break;
        case ADD_OPCODE:
            break;
        case SUB_OPCODE:
            break;
        case XOR_OPCODE:
            break;
        case OR_OPCODE:
            break;
        case AND_OPCODE:
            break;
        default:
            //Check for lui and sbreak;
            if (instr == SBREAK_OPCODE)
                break;
            else if (opcode == LUI_OPCODE)
                break;
            else if (opcode == JAL_OPCODE)
                break;
            goto badop;
            break;
    }

    switch(ret_instr->instr_type) {
        case I_INSTR:
            ret_instr->instr.i.rs1 = RS1_BITFIX(instr);
            ret_instr->instr.i.rd = RD_BITFIX(instr);
            ret_instr->instr.i.imm = IMM12_BITFIX(instr);
#ifdef DEBUG
            fprintf(stderr,"IMM_OP:%x SRC1:%x DST:%x IMM:%x\n", op, ret_instr->instr.i.rs1, ret_instr->instr.i.rd, ret_instr->instr.i.imm);
#endif
            break;
        case R_INSTR:
#ifdef DEBUG
#endif
            break;
        case SB_INSTR:
#ifdef DEBUG
#endif
            break;
    }

return true;

badop:
#ifdef DEBUG
    fprintf(stderr,"BADOP\n");
    fprintf(stderr,"OP: %x\n",op);
#endif
    return false;
}
