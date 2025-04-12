#pragma once
#include "storage.h"

typedef struct {
    StorageEngine *storage; 
} REPL;

void repl_start(REPL *repl);
