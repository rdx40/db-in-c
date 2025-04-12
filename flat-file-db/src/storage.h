// src/storage.h
#pragma once
#include <stdint.h>
#include <stdio.h>  

typedef struct {
    uint32_t id;
    char username[32];
    char email[255];
} Row;

typedef struct {
    FILE *file;
    const char *filename;
} StorageEngine;

void storage_init(StorageEngine *, const char *filename);
void storage_close(StorageEngine *);
int storage_insert(StorageEngine *, Row *row);
int storage_select_all(StorageEngine *);
