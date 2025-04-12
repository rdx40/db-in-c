// src/storage.c
#include "storage.h"
#include <stdio.h>
#include <stdlib.h>  

void storage_init(StorageEngine *s, const char *filename) {
    s->filename = filename;
    s->file = fopen(filename, "ab+");
    if (!s->file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
}

void storage_close(StorageEngine *s) {
    if (s->file) {
        fclose(s->file);
        s->file = NULL;
    }
}

int storage_insert(StorageEngine *s, Row *row) {
    if (!s->file) return 0;
    return fwrite(row, sizeof(Row), 1, s->file) == 1;
}

int storage_select_all(StorageEngine *s) {
    if (!s->file) return 0;
    
    rewind(s->file);
    Row row;
    while (fread(&row, sizeof(Row), 1, s->file) == 1) {
        printf("(%u, %s, %s)\n", row.id, row.username, row.email);
    }
    return feof(s->file);
}
