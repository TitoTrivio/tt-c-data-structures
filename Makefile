# OS dependent configuration

ifeq ($(OS), Windows_NT)
    DETECTED_OS := $(OS)
else
    DETECTED_OS := $(shell uname -s);
endif

ifeq ($(DETECTED_OS), Windows_NT)
    LIB_EXT  := .dll
    PIC_FLAG :=
else
    LIB_EXT  := .so
    PIC_FLAG := -fPIC
endif

# Build configuration

CC := gcc

BUILD ?= debug

# Project configuration

TARGET := tt_c_data_structures

BUILD_DIR := build/$(BUILD)
BIN_DIR   := bin/$(BUILD)
SRC_DIRS  := src
INC_DIRS  := include

LIBRARY := $(BIN_DIR)/lib$(TARGET)$(LIB_EXT)

# Files

SRC_FILES := $(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.c))
OBJ_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(patsubst %.c,$(BUILD_DIR)/%.d,$(SRC_FILES))

# Flags

INC_FLAGS  := $(foreach D,$(SRC_DIRS) $(INC_DIRS),-I$(D))
DEP_FLAGS  := -MMD -MP
C_STANDARD := -std=c23
WARN_FLAGS := -Wall -Wextra -Wpedantic

CPPFLAGS := $(INC_FLAGS) $(DEP_FLAGS)
CFLAGS   := $(C_STANDARD) $(WARN_FLAGS) $(PIC_FLAG)
LDFLAGS  := -shared

RELEASE_FLAGS := -O3
DEBUG_FLAGS   := -O0 -g

ifeq ($(BUILD), release)
    CFLAGS += $(RELEASE_FLAGS)
else ifeq ($(BUILD), debug)
    CFLAGS += $(DEBUG_FLAGS)
else
    $(error Invalid BUILD value: $(BUILD). Use 'release' or 'debug')
endif

# Targets

all: $(LIBRARY)

$(LIBRARY): $(OBJ_FILES)
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean

# Include dependencies

-include $(DEP_FILES)

