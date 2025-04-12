// src/repl.c
#include "repl.h"
#include "storage.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void repl_start(REPL *repl) {
    char input[1024];
    StorageEngine *storage = repl->storage;  
    
    while (1) {
        printf("db > ");
        if (!fgets(input, sizeof(input), stdin)) break;
        
        char *command = strtok(input, " \n");
        if (!command) continue;

        if (strcmp(command, "insert") == 0) {
            Row row;
            char *id_str = strtok(NULL, " ");
            char *username = strtok(NULL, " ");
            char *email = strtok(NULL, " \n");

            if (!id_str || !username || !email) {
                printf("Syntax: insert <id> <username> <email>\n");
                continue;
            }

            row.id = atoi(id_str);
            strncpy(row.username, username, 31);
            strncpy(row.email, email, 254);
            row.username[31] = row.email[254] = '\0';

            if (!storage_insert(storage, &row)) {
                printf("Failed to insert.\n");
            }
        } 
        else if (strcmp(command, "select") == 0) {
            storage_select_all(storage);
        } 
        else if (strcmp(command, ".exit") == 0) {
            break;
        } 
        else {
            printf("Unknown command: %s\n", command);
        }
    }
}
