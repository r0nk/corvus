int tick(Engine * engine){
	engine->iterations++;
	int i,j;
	for(i=0;i<(engine->birdArray.size);i++){
		updateBird(&engine->birdArray.birds[i]);
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
