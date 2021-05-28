# CA-Assignment1
by Tejdeep Gutta(IMT2020102)
   Jayam Shanmukha Bhuvan (IMT2020506)
    
Implementing IAS architecture using cpp.


Functions in the implementation:
Fetch- This function fetches the instructions.
Decodeandexecute- This function decodes the opcode and executes the function.

Our Assumptions
->In multiply operation as our systems are 64 bit computers we considered the value to be stored in MQ and AC as 3 bit each instaed of 40 bit each.
->If we want to have a left instruction having halt instruction and right instruction with any other instruction then for left instruction the opcode must be zero but its address field should be non zero. If not it is considered as a single instruction or just the right instruction without a left instruction.

Test case-1:

memory[0] = 0x090200B010;          LoadMQ,M(x)  MUL M(x)

memory[1] = 0x0B03001040;          MUL M(x)     MUL M(x)

memory[2] = 0x0C04000000;          DIV M(x)

memory[32] = 1;

memory[16] = 2;

memory[48] = 3;

memory[64] = 6;



Test case-2:

memory[0] = 0x0101005020;         LOAD M(x)      ADD M(x)

memory[1] = 0x0E00200000;         JUMP M(x20:39) HALT

memory[2] = 0x0C04006030;         DIV M(x)       SUB M(x) 

memory[3] = 0x2104000000;         STOR M(x)      HALT

memory[32] = 1;

memory[16] = 2;

memory[48] = 3;

memory[64] = 6;



