Strand mutate(Strand parentStrand){
	Strand strand = malloc(MAX_TEXT_SPACE);
	memcpy(strand,parentStrand,MAX_TEXT_SPACE);
	int i,j;
	for(i=0;i<MAX_TEXT_SPACE;i++){
		if((rand()%100)<1){//1 percent chance of mutation
			j=rand()%8;
			switch(j){
				case 0:
					strand[i]='>';
					break;
				case 1:
					strand[i]='<';
					break;
				case 2:
					strand[i]='+';
					break;
				case 3:
					strand[i]='-';
					break;
				case 4:
					strand[i]=',';
					break;
				case 5:
					strand[i]='.';
					break;
				case 6:
					strand[i]='[';
					break;
				case 7:
					strand[i]=']';
					break;
			}
		}
	}
	return strand;
}
Bird createBird(Strand strand){
	Bird bird;
	bird.fat = STARTING_FAT + rand()%50;
	bird.strand = mutate(strand);
	bird.vm = createVirtualMachine(bird.strand);
	return bird;
}
BirdArray generateBirds(){
	int i;
	BirdArray birdArray;
	birdArray.size=MAX_BIRDS;
	birdArray.birds=calloc(sizeof(Bird),MAX_BIRDS+1);
	Strand def = malloc(MAX_TEXT_SPACE);
	for(i=0;i<MAX_TEXT_SPACE;i++){
		def[i]='<';
	}
	for(i=0;i<MAX_BIRDS;i++){
		birdArray.birds[i]=createBird(def);
	}
	return birdArray;
}
Bird * fattest(BirdArray ba){
	//return the most fat bird in ba
	int fattest=0;//index of the fattest
	int i;
	for(i=0;i<(ba.size);i++)
		if((ba.birds[i].fat) > (ba.birds[fattest].fat))
			fattest=i;
	return &(ba.birds[fattest]);
}
int updateBird(Bird * bird){
	int j;
	if((bird->fat)>0){
		bird->fat--;
		j=step(&(bird->vm),bird->x);
		if(j!=-1)
			return j;
	}else
		bird->fat=0;
	return -1;
}
void freeBird(Bird * bird){
	//obligatory AND THIS BIRD YOU CANNOT CHAAAAAAAAAAAAAAAAAAAAAAAAAAANGE
	freeVirtualMachine(bird->vm);
}
void replaceBird(Bird * to,Bird * from){
	freeBird(to);
	*to = createBird(from->strand);
}
