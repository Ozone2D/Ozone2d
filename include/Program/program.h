#pragma once

#include "program_data.h"

struct ProgramData* createProgramData();
void freeProgramData(struct ProgramData* _data);
void programLoop(struct ProgramData* _data);
