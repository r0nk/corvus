int isOpcode(byte o){
	return (o=='>'||o=='<'||
		o=='+'||o=='-'||
		o=='.'||o==','||
		o=='['||o==']');
}
void freeVirtualMachine(VirtualMachine vm){
	free(vm.text);
	free(vm.data);
	//other two are pointers to above so we don't have to worry about them
}
byte * jumpDestination(VirtualMachine vm){
	byte target;
	int movement;
	int level = 0;
	byte * destination=vm.pc;
	if(*vm.pc=='['){
		target=']';
		movement=1;
	}else if(*vm.pc==']'){
		target='[';
		movement=-1;
	}else
		return vm.pc;
	while(!(level<1&&*destination==target)){
		destination+=movement;
		if(destination>=(vm.text+MAX_TEXT_SPACE) || destination<=vm.text)
			return vm.pc;
		if(*destination==*vm.pc)
			level++;
		if(*destination==target)
			level--;
	}
	return destination;
}
int step(VirtualMachine * vm,int x){//do one instruction
	if((vm->pc)>=(vm->text+MAX_TEXT_SPACE) || (vm->pc)<=vm->text)
		vm->pc=vm->text;
	if((vm->dc)>=(vm->data+MAX_DATA_SPACE) || (vm->dc)<=vm->data)
		vm->dc=vm->data + (MAX_DATA_SPACE/2);
	switch(*vm->pc){
		case '>':
			vm->dc++;
			break;
		case '<':
			vm->dc--;
			break;
		case '+':
			*vm->dc++;
			break;
		case '-':
			*vm->dc--;
			break;
		case '.':
			*vm->pc++;
			return *vm->dc;
		case ',':
			*vm->dc=(byte)x;
			break;
		case '[':
			if(*vm->dc)
				break;
		case ']':
			if(!*vm->dc)
				break;
			vm->pc=jumpDestination(*vm);
		default:
			break;
	}
	vm->pc++;
	return -1;
}
VirtualMachine createVirtualMachine(byte * text){
	VirtualMachine vm;
	if(text==NULL)
		text = malloc(MAX_TEXT_SPACE);
	else
		vm.text = text;
	vm.data = calloc(sizeof(byte),MAX_DATA_SPACE);
	vm.pc = vm.text;//program counter at start of program
	vm.dc = vm.data + (MAX_DATA_SPACE/2);//we want to start in the middle
	return vm;
}
