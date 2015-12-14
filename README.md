# RISCY VM
RISCVY VM is an attempt at writing a Dynamic Translator for the RISC-V ISA. Insperation on the design of the VM is taken from QEMU, a Fast and Protable Dynamic Translator by Fabrice Bellard. The current state is more of a proof of concept than a useful or fully fuctioning tool. NOTE: Programs are expected to be in little endian format.

## Components:
### VA Space Simulation
As a naive solution in current builds, the VA space will be a flat array with simple bounds checking. There will be no marking the address space in any way (ie: Code Segment, WT/WB, etc.).
### Translation of RISC-V Machine Code
Similarly to QEMU, RISCY VM will translate machine code operations into micro-operations.
### Emulation of Registers
Registers will be emulated in memory as part of an array.
### Debugger
The debugger will only be activated at the exceution of the SBREAK instruction.

## ISA
There will only be a subset of the RV32I ISA Implemented. Instructions that will be simulated are contained in the following table.

| Acronym        | Instruction           | Type  | Funct3 | Opcode[6:2] |
| ------------- | ------------------------- | ----- | -------- | -------- |
| LUI | Load Unsigned Immediate | I | N/A | 01101 |
| JAL |Jump And Link | I |000|11001|
| BEQ| Branch =|SB|000|11000|
|BNE | Branch != |SB|001|11000|
|BLT| Branch <|SB|100|11000|
|BGE| Branch >=|SB|101|11000|
|BLTU|Branch <= Unsigned|SB|110|11000|
|BGEU| Breanch >= Unsigned|SB|111|11000|
|LW| Load Word |I|010|00000|
|SW|Store Word| I|010|01000|
|ADDI| ADD Immediate|I|000|00100|
|XORI|XOR Immediate |I|100|00100|
|ORI| OR Immediate|I|110|00100|
|ANDI| AND Imemdiate|I|111|00100|
|ADD| ADD|R|000|01100|
|SUB| SUB |R|000|01100|
|XOR|XOR|R|100|01100|
|OR|OR|R|110|01100|
|AND|AND|R|111|01100|
|SBREAK|SBREAK|I|000|11100|
###### Note: NOP is encoded as ADDI %0,%0,bash
 .
 
## Future Work
- Translation for the full RV32I Instruction set
- Dynamicallly allocated memory space WITH memory protections
- A cache of previously translated instrucitons


###### Note: No need for flags management (it doesn't appear to exist in RISC-V)
