# OS detection

ifeq ($(OS), Windows_NT)
    DETECTED_OS := $(OS)
else
    DETECTED_OS := $(shell uname -s)
endif

# Build configuration

CC := gcc
AR := ar

BUILD ?= debug

# Project configuration

TARGET := tt_c_data_structures

BUILD_DIR := build/$(BUILD)
BIN_DIR   := bin/$(BUILD)
SRC_DIRS  := src
INC_DIRS  := include

STATIC_LIBRARY := $(BIN_DIR)/lib$(TARGET)
SHARED_LIBRARY := $(BIN_DIR)/lib$(TARGET)

ifeq ($(DETECTED_OS), Windows_NT)
    IMPORT_LIBRARY := $(BIN_DIR)/lib$(TARGET)

    STATIC_LIBRARY := $(STATIC_LIBRARY).a
    SHARED_LIBRARY := $(SHARED_LIBRARY).dll
    IMPORT_LIBRARY := $(IMPORT_LIBRARY).dll.a
else
    STATIC_LIBRARY := $(STATIC_LIBRARY).a
    SHARED_LIBRARY := $(SHARED_LIBRARY).so
endif

# Files

SRC_FILES := $(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.c))
OBJ_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES := $(patsubst %.c,$(BUILD_DIR)/%.d,$(SRC_FILES))

# Flags

INC_FLAGS  := $(foreach D,$(SRC_DIRS) $(INC_DIRS),-I$(D))
DEP_FLAGS  := -MMD -MP
C_STANDARD := -std=c23
WARN_FLAGS := -Wall -Wextra -Wpedantic

CPPFLAGS   := $(INC_FLAGS) $(DEP_FLAGS)
CFLAGS     := $(C_STANDARD) $(WARN_FLAGS)
LDFLAGS    := -shared
AR_OPTIONS := rcs

ifeq ($(BUILD), release)
    CFLAGS += -O2
else ifeq ($(BUILD), debug)
    CFLAGS += -O0 -g
else
    $(error Invalid BUILD value: $(BUILD). Use 'release' or 'debug')
endif

ifeq ($(DETECTED_OS), Windows_NT)
    LDFLAGS += -Wl,--out-implib,$(IMPORT_LIBRARY)
else
    CFLAGS += -fPIC
endif

# Targets

all: static shared

static: $(STATIC_LIBRARY)

shared: $(SHARED_LIBRARY)

$(STATIC_LIBRARY): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(AR) $(AR_OPTIONS) $@ $^

$(SHARED_LIBRARY): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all static shared clean

# Include dependencies

-include $(DEP_FILES)

