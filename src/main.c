#include <stdio.h>
#include "program.h"

int main() {
    printf("\x1B[31mWelcome To Ozone2d!\033[0m\n");

	// Allocating and initializing all the data that will be used during runtime
	struct ProgramData* data = createProgramData();

	// Running the program with the allocated data
	programLoop(data);

	// Freeing the program data
	freeProgramData(data);



    return 0;
}