#include<bits/stdc++.h>
#include<math.h>

using namespace std;

long int PC=0;
long int memory[1000];
long int MBR;
long int MAR;
long int IR;
long int IBR;
long int AC;
long int MQ;
long int run = 1;
int JUMP = 0;
int JUMP_RIGHT = 0;


void decode_execute_ins(long int IR, long int MAR)
{
	switch(IR)
	{
		case 0:
			{
				printf("HALT \n");
				run = 0;
				break;
			}
		case 1:
			{
				AC = memory[MAR];
				printf("LOAD M(x) function is activated\n");
				printf("%ld is loaded to accumulator \n",AC);
				break;
			}
		case 2:
			{
				AC = -(memory[MAR]);
				printf("LOAD -M(x) function is activated\n");
				printf("%ld is loaded to accumulator \n",AC);
				break;
			}
		case 3:
			{
				if(memory[MAR]>=0)
					AC = memory[MAR];
				else
					AC = -(memory[MAR]);
				printf("LOAD |M(x)| function is activated\n");
				printf("%ld is loaded to accumulator \n",AC);
				break;
			}
		case 4:
			{
				if(memory[MAR]>=0)
					AC = -(memory[MAR]);
				else
					AC = memory[MAR];
				printf("LOAD -|M(x)| function is activated\n");
				printf("%ld is loaded to accumulator \n",AC);
				break;
			}
		case 5:
			{
				AC = AC + memory[MAR];
				printf("ADD M(x) function is activated\n");
				printf("The resultant sum is %ld \n",AC);
				break;
			}
		case 6:
			{
				AC = AC - memory[MAR];
				printf("SUB M(x) function is activated\n");
				printf("The resultant difference is %ld \n",AC);
				break;
			}
		case 7:
			{
				if(memory[MAR]>=0)
					AC = AC + memory[MAR];
				else
					AC = AC - memory[MAR];
				printf("ADD |M(x)| function is activated\n");
				printf("The resultant sum is %ld \n",AC);
				break;
			}
		case 8:
			{
				if(memory[MAR]>=0)
					AC = AC - memory[MAR];
				else
					AC = AC + memory[MAR];
				printf("SUB |M(x)| function is activated\n");
				printf("The resultant difference is %ld \n",AC);
				break;
			}
		case 9:
			{
				MQ = memory[MAR];
				printf("LOAD MQ,M(x) function is activated\n");
				printf("%ld is loaded to MQ \n",MQ);
				break;
			}
		case 10:
			{
				AC = MQ ;
				printf("LOAD MQ function is activated\n");
				printf("%ld is loaded to Accumulator \n",AC);
				break;
			}
		case 13:
			{
				PC = memory[MAR];
				JUMP = 1;
				printf("JUMP M(x,0:19) function is activated\n");
				printf("next instruction is fetched from location %ld\n",PC);
				break;
			}
		case 14:
			{
				PC = memory[MAR];
				JUMP_RIGHT = 1;
				JUMP = 1;
				printf("JUMP M(x,20:39) function is activated\n");
				printf("next instruction is fetched from location %ld\n",PC);
				break;
			}


	}


}


int fetch()
{
	int n;
	
	
	if(JUMP_RIGHT == 0)
	{
		MBR = memory[PC];
		printf("The instruction in memory location of PC is sent to MBR \n");

		if( MBR >= 1048576 && MBR < 1099511627776 )
		{
			printf("left instruction is present \n");
		
			IR = MBR/4294967296;
			printf("The opcode of left instruction is loaded into IR \n");
		
			MAR = (MBR/1048576)%4096;
			printf("The address of the desired value is loaded into MAR \n");
		
			IBR = MBR % 1048576;
			printf("right instruction is loaded into MBR \n");

			if(run == 1)
			{
				PC += 1;
				printf("PC is incremented\n");
			}

			printf("the opcode is sent for decoding and followed by execution of the instruction \n");
			decode_execute_ins(IR,MAR);
			printf("\n");

			if(JUMP == 0 && run == 1)
			{
				IR = IBR/4096;
				printf("The opcode of right instruction is loaded into IR \n");

	
				MAR = IBR % 4096;
				printf("The address of the desired value is loaded into MAR \n");
		
				printf("the opcode is sent for decoding and followed by execution of the instruction \n");
				decode_execute_ins(IR,MAR);
				printf("\n");
			}
			JUMP = 0;
		}
		else 
		{

			printf("There is no left instruction");
		
			IR = MBR/4096;
			printf("The opcode of right instruction is loaded into IR \n");
		
			MAR = MBR % 4096;
			printf("The address of the desired value is loaded into MAR \n");

			if(run == 1)
			{
				PC += 1;
				printf("PC is incremented\n");
			}

			printf("the opcode is sent for decoding and followed by execution of the instruction \n");
			decode_execute_ins(IR,MAR);
			printf("\n");
		}
	}
	else
	{
		if( MBR >= 1048576 && MBR < 1099511627776 )
		{
			MBR = (memory[PC]) % 1048576;
			printf("The instruction in memory location of PC is sent to MBR \n");

			IR = MBR/4096;
			printf("The opcode of right instruction is loaded into IR \n");

			MAR = MBR % 4096;
			printf("The address of the desired value is loaded into MAR \n");

			if(run == 1)
			{
				PC += 1;
				printf("PC is incremented\n");
			}

			printf("the opcode is sent for decoding and followed by execution of the instruction \n");
			decode_execute_ins(IR,MAR);
			printf("\n");
		}
		else
		{
			MBR = memory[PC];
			printf("The instruction in memory location of PC is sent to MBR \n");

			IR = MBR/4096;
			printf("The opcode of right instruction is loaded into IR \n");

			MAR = MBR % 4096;
			printf("The address of the desired value is loaded into MAR \n");

			if(run == 1)
			{
				PC += 1;
				printf("PC is incremented\n");
			}

			printf("the opcode is sent for decoding and followed by execution of the instruction \n");
			decode_execute_ins(IR,MAR);
			printf("\n");
		}
		JUMP_RIGHT = 0;
	}


	return 0;
}

int main()
{
	memory[0] = 0x0C02002010;
	memory[1] = 0x090300A000;
	memory[2] = 0x000300A000;
	memory[32] = 1;
	memory[16] = 6;
	memory[48] = 7;

	while(run)
	{
		fetch();
		
	}
}








