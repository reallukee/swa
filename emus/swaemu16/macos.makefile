# ***********************
# swaemu16 macOS Makefile
# ***********************
#   v2.2

TARGET_NAME ?= swaemu16
TARGET_EXT  ?=
OUT_DIR     ?= ../../bin/macos
OBJ_DIR     ?= ../../obj/macos/$(TARGET_NAME)$(TARGET_EXT)
SRC_DIR     ?= src
INCLUDE_DIR ?= include

LIBSWA16_NAME    ?= swa16
LIBSWA16_LIB     ?= ../../bin/macos
LIBSWA16_INCLUDE ?= ../../libs/libswa16/include

CC      = clang
CFLAGS  = -std=c23 -Wall -Wextra -fPIC -I$(SRC_DIR) -I$(LIBSWA16_INCLUDE) -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIBSWA16_LIB) -l$(LIBSWA16_NAME)

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
