#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <inttypes.h>

#include "defs.h"
#include "parse.h"

// Access a single byte from the emulated program's address space
// return 0 if bad memory access (SEGFAULT)
char access_mem_b(char read, addr address) {return 0;}


// Local Globals
static void *address_space = NULL;
static uint32_t as_size = 0xffffffff;
static uint32_t *regfile = NULL;

int main(int argc, char ** argv) {

    const char cmdopts[] = "f:s:";
    char opt;
    FILE *infile = NULL;

    // 3. Execution Loop:
    //       Parse machine code line into instruction
    //       Translate Instruction to micro-op
    //       Perform micro-op

    if (argc == 1) BADARGS;

    // Process the arglist
    while (-1 != (opt = getopt(argc, argv, cmdopts))) {
        switch (opt) {
            case 'f': // get file
                infile = fopen(optarg, "r");
                if (!infile) BADINFILE;
                break;
            case 's': // get size of as
                //Check if the value was negative.
                if (optarg[0] == '-') BADINT; //FIXME: Make this check the whole string
                as_size = atoi(optarg);
                break;
            case '?':
                BADARGS;
                break;
        }
    }
    
    
    if (!infile) BADARGS; //Must give a file as input
    
    address_space = malloc(as_size);
    if (!address_space) BADASALLOC;

    regfile = malloc(sizeof(long int)*RISCV_REGS);
    if (!address_space) BADREGALLOC;

    // Possible additions to arglist could be input type (ie: reading assembly)
    
    uint32_t machine_inst = 0;
    instruction cur_instr;

    for(;;) {
        //Read in a single instruction from the file.
        //TODO: Later need to handle for ELF binaries not just flat program.
        if (!fread(&machine_inst, 4, 1, infile))
            break;

        // Parse the machine instruction into instr struct
        if (!parse_instr(&machine_inst, &cur_instr)) {
            WARN_INSTR;
#ifdef DEBUG
            fprintf(stderr,"Bad instr: %x\n", machine_inst);
#endif
            continue;
        }

        // Translate the instr struct into a micro-op
        

        // Perform micro-op
    }

    // NEED: 
    //  - Parser for machine code
    //  - micro-op translations for instructions
    return(0);
}

