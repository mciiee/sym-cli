CC=clang
CFLAGS=-Wall -Wextra -Werror -std=c23
CCFLAGS=

SRC_DIR=src
BUILD_DIR=build


$(BUILD_DIR)/sym-cli: $(BUILD_DIR)/sym-cli.o
	$(CC) $(CCFLAGS) $< -o $@

$(BUILD_DIR)/sym-cli.o: $(SRC_DIR)/sym-cli.c build
	$(CC) -c $(CFLAGS) $< -o $@

build:
	mkdir -p build

build-static: static


static: $(BUILD_DIR)/sym-cli.o
	$(CC) $(CCFLAGS) -static -c $(CFLAGS) $< -o $@
