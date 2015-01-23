#include "types.h"

#define MAX_TEXT_SPACE 80
#define MAX_DATA_SPACE 1028

typedef struct{
	byte * pc;//program counter
	byte * dc;//data counter 
	byte * text;//array of text (program code) space
	byte * data;//array of data space
} VirtualMachine;
#include "virtualMachine.c"
