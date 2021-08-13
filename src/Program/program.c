#include "program.h"
#include "window.h"
#include <stdlib.h>

struct ProgramData* createProgramData(){
	struct ProgramData* data = (struct ProgramData*)malloc(sizeof(struct ProgramData));

	// Initializing the data
	data->window.width = 800;
	data->window.height = 600;
	
	return data;
}

void freeProgramData(struct ProgramData* _data){
	free(_data);
}

void programLoop(struct ProgramData* _data){
	createWindow(&_data->window);

	destroyWindow(&_data->window);
}
