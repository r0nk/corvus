#include <curses.h>

void initGraphics(){
	initscr();
	start_color();
	use_default_colors();
	init_color(1,700,700,1000);
	init_color(2,500,250,0);
	init_color(0,0,0,0);
	init_pair(0,COLOR_WHITE,-1);
	init_pair(1,COLOR_CYAN,-1);//(cyan on default)
	init_pair(2,COLOR_WHITE,2);
	init_pair(3,1,-1);
	init_pair(4,COLOR_GREEN,-1);
	init_pair(5,COLOR_BLUE,-1);
	init_pair(6,COLOR_YELLOW,-1);
	init_pair(7,COLOR_MAGENTA,-1);
	init_pair(8,COLOR_WHITE,COLOR_BLUE);
	init_pair(9,COLOR_BLACK,COLOR_YELLOW);
	init_pair(10,COLOR_BLACK,COLOR_RED);
	init_pair(11,COLOR_BLACK,COLOR_WHITE);
	cbreak();
	noecho();		
}
void drawBirds(BirdArray birdArray){
	int i,j=0;
	for(i=0;i<birdArray.size;i++){
		mvprintw(j++,0,"fat: %i\n",birdArray.birds[i].fat);
		mvprintw(j++,0,"%s\n",birdArray.birds[i].vm.text);
		mvprintw(j++,0,"%s\n",birdArray.birds[i].vm.data);
	}
}
void redraw(Engine engine){
	erase();
	drawBirds(engine.birdArray);
	mvprintw(LINES,0,"engine.iterations:%i",engine.iterations);
	refresh();
}
