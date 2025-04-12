#include "storage.h"
#include "repl.h"

int main() {
    StorageEngine storage;
    storage_init(&storage, "database.db");

    REPL repl;
    repl.storage = &storage;  
    repl_start(&repl);      

    storage_close(&storage);
    return 0;
}
