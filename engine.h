#include "bird.h"
/*The Engine is like a game engine, it handles everthing in the virtual
  little world of birds*/
typedef struct{
	byte (*f)(byte x);//the target function the birds are trying to reach
	unsigned long long int iterations;//how many times we have ticked
	BirdArray birdArray;
} Engine;
#include "engine.c"
