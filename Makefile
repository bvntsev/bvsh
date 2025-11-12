# === config ===
include config.mk

# get the files
SRCS := $(wildcard $(SRC_DIR)/*.c) 
# replace the .c names to .o
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

all: $(BIN) run

$(BIN): make_dir clean $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir p $@

run:
	$(BIN)

run_gdb:
	gdb $(BIN)

clean:
	rm -f $(BIN_DIR)/$(BIN_NAME)
	rm -f temp/*

make_dir:
	mkdir -p build/ temp/


.PHONY: all clean 
