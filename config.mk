CC = gcc

CFLAGS = -W -Wall -Wextra -std=c11 -Iinclude -O1 -g

LDFLAGS =

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = build
BIN_NAME = bvsh
BIN = $(BIN_DIR)/$(BIN_NAME)
