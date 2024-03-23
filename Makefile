# This work is hereby placed into the public domain. The author(s) waive
# all copyright and related rights (including but not limited to economic
# and moral rights) to the maximum extent permitted by law.

# Author(s):
#         Indraj Gandham <indraj@posteo.net> (2024)

CC := gcc
LD := gcc

DEBUG := -O0 -g3 -fno-omit-frame-pointer
STANDARD := -O2

CFLAGS := $(DEBUG) -Werror -Wextra -std=c99 -pedantic-errors
LDFLAGS :=

SRC_DIR := src
OBJ_DIR := obj

OUT := test

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(OUT)

.PHONY: all clean

all: $(OUT)
