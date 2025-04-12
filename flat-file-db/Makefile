CC = gcc
CFLAGS = -Wall -Wextra
BUILD_DIR = build
SRC_DIR = src

all: $(BUILD_DIR)/db_engine

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/db_engine: $(SRC_DIR)/main.c $(SRC_DIR)/storage.c $(SRC_DIR)/repl.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR) database.db

run: $(BUILD_DIR)/db_engine
	@echo "Running database engine..."
	@./$(BUILD_DIR)/db_engine

test: all run  # Add this target to build and run

.PHONY: all clean run