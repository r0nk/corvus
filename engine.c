int tick(Engine * engine){
	engine->iterations++;
	int i,j=0;
	for(i=0;i<(engine->birdArray.size);i++){
		j=updateBird(&engine->birdArray.birds[i]);
		if(j==engine->f(engine->birdArray.birds[i].x)){
			engine->birdArray.birds[i].x++;
			engine->birdArray.birds[i].fat+=CARBS;
			if(engine->birdArray.birds[i].x>250){
				endwin();
				fprintf(stderr,"\n###WINNING STRAND###\n%s\n",engine->birdArray.birds[i].strand);
				exit(5);
			}
		}else if(j!=(-1)){
			engine->birdArray.birds[i].fat-=POISON;
		}
		if(engine->birdArray.birds[i].fat<=0)
			replaceBird(    &engine->birdArray.birds[i],
					fattest(engine->birdArray));
	}
}
void freeEngine(Engine * engine){
	for(;engine->birdArray.size>0;engine->birdArray.size--)
		freeBird(&engine->birdArray.birds[engine->birdArray.size]);
	free(engine->birdArray.birds);
}
