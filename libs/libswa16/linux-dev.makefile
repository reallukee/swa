# ***********************
# libswa16 Linux Makefile
# ***********************
#   v2.1

TARGET_NAME ?= libswa16
TARGET_EXT  ?=
OUT_DIR     ?= bin/linux
OBJ_DIR     ?= obj/linux
SRC_DIR     ?= src
INCLUDE_DIR ?= include

CC      = gcc
CFLAGS  = -std=c23 -Wall -Wextra -fPIC -I$(SRC_DIR) -I$(INCLUDE_DIR)
LDFLAGS =

ifeq ($(debug),1)
CFLAGS += -Werror -Wno-error=unused \
          -Wmissing-prototypes \
          -Wstrict-prototypes \
          -Wmissing-declarations
endif

SRC     = $(shell find $(SRC_DIR) -name '*.c')
OBJ     = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
TARGET  = $(OUT_DIR)/$(TARGET_NAME)$(TARGET_EXT)

.DEFAULT_GOAL := help

help:
	@echo "make build    "
	@echo "make rebuild  "
	@echo "make clear    "
	@echo "make fullclear"

build: $(TARGET)

$(TARGET): $(OBJ) | $(OUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)

	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR) $(OBJ_DIR):
	mkdir -p $@

rebuild: clear build

clear:
	rm -rf $(OBJ_DIR)

fullclear:
	rm -rf $(OUT_DIR) $(OBJ_DIR)

.PHONY: help build rebuild clear fullclear
