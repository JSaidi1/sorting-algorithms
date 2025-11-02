# ================================================
# mingw32-make     # same as mingw32-make compile
# mingw32-make run
# mingw32-make clean
# ================================================

# ================================================
# Compiler setup
# ================================================
CC        := gcc
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build
TARGET    := my_program
CFLAGS    := -I$(INC_DIR) -Wall -Wextra -std=c11

# ================================================
# Sources / Objects
# ================================================
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# ================================================
# OS detection
# ================================================
ifeq ($(OS),Windows_NT)
    EXE      := .exe
    MKDIRCMD := mkdir $(BUILD_DIR) 2>nul || ver >nul
    RUNCMD   := $(BUILD_DIR)\$(TARGET)$(EXE)
    CLEANCMD := rmdir /S /Q $(BUILD_DIR) 2>nul || echo Nothing to clean
else
    EXE      :=
    MKDIRCMD := mkdir -p $(BUILD_DIR)
    RUNCMD   := ./$(BUILD_DIR)/$(TARGET)
    CLEANCMD := rm -rf $(BUILD_DIR)
endif

# ---------- Link ----------
$(BUILD_DIR)/$(TARGET)$(EXE): $(OBJS)
	@echo Linking $@ ...
	@$(CC) $(OBJS) -o $@ || (echo Link failed && exit 1)

# ---------- Compile ----------
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo Compiling $< ...
	@$(CC) $(CFLAGS) -c $< -o $@ || (echo Compile failed: $< && exit 1)

# ---------- Ensure build directory exists ----------
$(BUILD_DIR):
	@$(MKDIRCMD)
	@echo Created build directory

# ================================================
# Targets
# ================================================
.PHONY: all compile run clean

# default target
all: compile
	@echo ========================================
	@echo      Compile Target (All Target) ...
	@echo ========================================

# ---------- Compile (Build) ----------
compile: clean $(BUILD_DIR)/$(TARGET)$(EXE)
	@echo ========================================
	@echo           Compile Target ...
	@echo ========================================
	@echo Build completed successfully!

# ---------- Run ----------
run: compile
	@echo ========================================
	@echo            Run Target ...
	@echo ========================================
	@echo Running $(TARGET) ...
	@$(RUNCMD)

# ---------- Clean ----------
clean:
	@echo ========================================
	@echo            Clean Target ...
	@echo ========================================
	@echo Cleaning build directory...
	@$(CLEANCMD)
	@echo Clean done.
