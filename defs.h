
#ifndef DEFS_H
#define DEFS_H

typedef unsigned long int addr;
#define true 1
#define false 0
#define USAGE "usage: <%s> -f FILE (-s as_size) \n"
#define RISCV_REGS 64

#define BADARGS {fprintf(stderr, USAGE, argv[0]); exit(-1);}
#define BADINFILE {fprintf(stderr, "Unable to open input file!\n"); exit(-1);}
#define BADINT {fprintf(stderr, "Bad int argument!\n"); exit(-1);}
#define BADASALLOC {fprintf(stderr, "Failed to allocate enough space for resident memory!\n"); exit(-1);}
#define BADREGALLOC {fprintf(stderr, "Failed to allocate enough space for registers!\n"); exit(-1);}
#define WARN_INSTR fprintf(stderr, "Bad or unsupported instruction read!\n");

#endif
