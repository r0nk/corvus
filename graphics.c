#include <curses.h>

void initGraphics(){
	initscr();
	start_color();
	use_default_colors();
	init_pair(0,COLOR_WHITE,-1);
	init_pair(1,COLOR_YELLOW,-1);//(cyan on default)
	init_pair(2,COLOR_YELLOW,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_YELLOW);
	cbreak();
	noecho();		
}
void drawBirds(BirdArray birdArray){
	int i,j=0;
	for(i=0;i<birdArray.size;i++){
		attron(COLOR_PAIR(i%2));
	//	mvprintw(j++,0,"fat: %i x: %i \n",birdArray.birds[i].fat,birdArray.birds[i].x);
		mvprintw(j++,0,"%s\n",birdArray.birds[i].vm.text);
	//	mvprintw(j++,0,"%s\n",birdArray.birds[i].vm.data);
		attroff(COLOR_PAIR(i%2));
	}
}
void redraw(Engine engine){
	erase();
	drawBirds(engine.birdArray);
	mvprintw(LINES,0,"engine.iterations:%i",engine.iterations);
	refresh();
//	getch(); //uncomment me if you wish to single step
}
