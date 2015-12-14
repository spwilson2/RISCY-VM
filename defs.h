#ifndef DEFS_H
#define DEFS_H

typedef unsigned long int addr;
#define true 1
#define false 0
#define USAGE "usage: <%s> -f FILE (-s as_size) \n"
#define RISCV_REGS 64

#define BADARGS {printf(USAGE, argv[0]); exit(-1);}
#define BADINFILE {printf("Unable to open input file!\n"); exit(-1);}
#define BADINT {printf("Bad int argument!\n"); exit(-1);}
#define BADASALLOC {printf("Failed to allocate enough space for resident memory!\n"); exit(-1);}
#define BADREGALLOC {printf("Failed to allocate enough space for registers!\n"); exit(-1);}


#endif
