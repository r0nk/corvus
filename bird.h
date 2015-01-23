#include "virtualMachine.h"

//how much getting the right answer gives
#define CARBS 200
#define MAX_BIRDS 6
#define STARTING_FAT 500
typedef struct{
	int fat;//how much food the bird has eaten, at 0, dead bird
	Strand strand;//Used to generate the VM text space.
	VirtualMachine vm;
} Bird;
typedef struct{
	int size;
	Bird * birds;
} BirdArray;
#include "bird.c"
