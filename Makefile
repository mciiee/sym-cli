CC=clang
CFLAGS=-Wall -Wextra -Werror -std=c23

SRC_DIR=src
BUILD_DIR=build

$(BUILD_DIR)/sym-cli: $(BUILD_DIR)/sym-cli.o
	$(CC) $< -o $@

$(BUILD_DIR)/sym-cli.o: $(SRC_DIR)/sym-cli.c
	$(CC) -c $(CFLAGS) $< -o $@

