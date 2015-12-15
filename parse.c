#ifdef DEBUG
#include <stdio.h>
#endif
#include <inttypes.h>

#include "parse.h"
#include "defs.h"

// Takes a pointer to the instruction to parse and prints the Assembly
char parse_instr(uint32_t *instr_ptr, instruction *ret_instr) {
    uint32_t instr = *instr_ptr;
    uint32_t op = OP_BITMASK(*instr_ptr);
    uint32_t opcode = OPCODE_BITMASK(*instr_ptr);
    
    // Test if the first two bits to assert RV32I
    if (!RV32I(instr))
        goto badop;
    
    //TODO: Assign op
    switch(op) {
        case BEQ_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __beq;
            break;
        case BNE_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __bne;
            break;
        case BLT_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __blt;
            break;
        case BGE_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __bge;
            break;
        case BLTU_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __bltu;
            break;
        case BGEU_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __bgeu;
            break;
        case SW_OPCODE:
            ret_instr->instr_type = SB_INSTR;
            ret_instr->instr.sb.op = __sw;
            break;
        case LW_OPCODE:
            ret_instr->instr_type = I_INSTR;
            ret_instr->instr.i.op = __lw;
            break;
        case ADDI_OPCODE:
            ret_instr->instr_type = I_INSTR;
            ret_instr->instr.i.op = __addi;
            break;
        case XORI_OPCODE:
            ret_instr->instr_type = I_INSTR;
            ret_instr->instr.i.op = __xori;
            break;
        case ORI_OPCODE:
            ret_instr->instr_type = I_INSTR;
            ret_instr->instr.i.op = __ori;
            break;
        case ANDI_OPCODE:
            ret_instr->instr_type = I_INSTR;
            ret_instr->instr.i.op = __andi;
            break;
        case ADD_OPCODE:
            ret_instr->instr_type = R_INSTR;
            ret_instr->instr.r.op = __add;
            break;
        case SUB_OPCODE:
            ret_instr->instr_type = R_INSTR;
            ret_instr->instr.r.op = __sub;
            break;
        case XOR_OPCODE:
            ret_instr->instr_type = R_INSTR;
            ret_instr->instr.r.op = __xor;
            break;
        case OR_OPCODE:
            ret_instr->instr_type = R_INSTR;
            ret_instr->instr.r.op = __or;
            break;
        case AND_OPCODE:
            ret_instr->instr_type = R_INSTR;
            ret_instr->instr.r.op = __and;
            break;
        default:
            //Check for lui and sbreak;
            //TODO: Handle U instructions
            if (instr == SBREAK_OPCODE) {
                break;
            }
            else if (opcode == LUI_OPCODE) {
                ret_instr->instr_type = U_INSTR;
                ret_instr->instr.r.op = __lui;
                break;
            }
            else if (opcode == JAL_OPCODE) {
                ret_instr->instr_type = U_INSTR;
                ret_instr->instr.r.op = __jal;
                break;
            }
            goto badop;
    }

    switch(ret_instr->instr_type) {
        case I_INSTR:
            ret_instr->instr.i.rs1 = RS1_BITFIX(instr);
            ret_instr->instr.i.rd = RD_BITFIX(instr);
            ret_instr->instr.i.imm = IMM_I_BITFIX(instr);
#ifdef DEBUG
            fprintf(stderr,"IMM_OP:%x SRC1:%x DST:%x IMM:%x\n", op, ret_instr->instr.i.rs1, ret_instr->instr.i.rd, ret_instr->instr.i.imm);
#endif
            break;
        case R_INSTR:
            ret_instr->instr.r.rs1 = RS1_BITFIX(instr);
            ret_instr->instr.r.rs2 = RS2_BITFIX(instr);
            ret_instr->instr.r.rd = RD_BITFIX(instr);
#ifdef DEBUG

#endif
            break;
        case SB_INSTR:
            ret_instr->instr.sb.imm = IMM_SB_BITFIX(instr);
            ret_instr->instr.sb.rs1 = RS1_BITFIX(instr);
            ret_instr->instr.sb.rs2 = RS2_BITFIX(instr);
        case U_INSTR:
            ret_instr->instr.u.imm = IMM_U_BITMASK(instr);
            ret_instr->instr.u.rd = RD_BITFIX(instr);
            break;

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
