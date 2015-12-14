#include "parse.h"
#include "defs.h"

// Takes a pointer to the instruction to parse and prints the Assembly
// TODO: Turn int into an intermediate instruction
char parse_instr(long int unsigned *instr_ptr, instruction *ret_instr) {
    long int unsigned instr = *instr_ptr;

    int unsigned opcode = OPCODE_BITMASK(*instr_ptr);
    int unsigned funct3 = FUNCT3_BITMASK(*instr_ptr);
    
    // Test if the first two bits to assert RV32I
    if (!RV32I(instr))
        goto badop;
    
    
    // Test with remainder of opcode for non-funct3 Instr's.
    // -    Test funct3's 
    
    switch(opcode) {
        case LUI_OPCODE:
            // TODO:Set rd addr
            break;
        case JAL_OPCODE:
            //TODO:Set rd addr
            break;
        case LW_OPCODE:
            if (funct3 != LW_FUNCT3)
                goto badop;
            //TODO: 
            break;
        case SW_OPCODE:
            if (funct3 != SW_FUNCT3)
                goto badop;
            break;
        case SBREAK_OPCODE:
            //TODO: Test all bits
            break;

        //GENERAL opcodes
        case BRANCH_OPCODE:
            switch (funct3) {
                case BEQ_FUNCT3:
                    break;
                case BNE_FUNCT3:
                    break;
                case BLT_FUNCT3:
                    break;
                case BGE_FUNCT3:
                    break;
                case BLTU_FUCT3:
                    break;
                case BGEU_FUNCT3:
                    break;
                default:
                    goto badop;
                    break;
            }
            break;
        case IMM_OPCODE:
            switch (funct3) {
                case ADDI_FUNCT3:
                    break;
                case XORI_FUNCT3:
                    break;
                case ORI_FUNCT3:
                    break;
                case ANDI_FUNCT3:
                    break;
                default:
                    goto badop;
                    break;
            }
            break;
        case REG_OPCODE:
            switch (funct3) {
                case ADD_FUNCT3:
                    break;
                case SUB_FUNCT3:
                    break;
                case XOR_FUNCT3:
                    break;
                case OR_FUNCT3:
                    break;
                case AND_FUNCT3:
                    break;
                default:
                    goto badop;
                    break;
            }
            break;
        default:
            goto badop;
            break;
    }

badop:
    return false;
}
