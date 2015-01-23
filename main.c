#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "engine.h"
#include "graphics.c"

byte targetFunction(byte x){
	/*this is the function the birds try to reach*/
	return x+2;
}
int main(){
	srand(time(NULL));//yay for !random
	Engine engine;
	engine.iterations=0;
	engine.f=targetFunction;
	engine.birdArray=generateBirds();
	initGraphics();
	while(1){
		tick(&engine);
		redraw(engine);
	}
	endwin();
}
