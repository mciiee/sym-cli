CC=clang
CFLAGS=-Wall -Wextra -Werror -std=c23 -D_POSIX_C_SOURCE=2
CCFLAGS=

SRC_DIR=src
BUILD_DIR=build


$(BUILD_DIR)/sym-cli: $(BUILD_DIR)/sym-cli.o  $(BUILD_DIR)/sym-table.o
	$(CC) $(CCFLAGS) $^ -o $@

$(BUILD_DIR)/sym-cli.o: $(SRC_DIR)/sym-cli.c build
	$(CC) -c $(CFLAGS) $< -o $@


$(BUILD_DIR)/sym-table.o: $(SRC_DIR)/sym-table.c build
	$(CC) -c $(CFLAGS) $< -o $@

build:
	mkdir -p build

build-static: static


static: $(BUILD_DIR)/sym-cli.o
	$(CC) $(CCFLAGS) -static -c $(CFLAGS) $< -o $@
