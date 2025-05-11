BUILD_DIR := build
CMAKE_DIR := cmake
PROGRAM := simulator
EXECUTABLE := $(BUILD_DIR)/$(PROGRAM)

.PHONY: all build clean run

# Compile all
all: build

# Build with cmake
build:
	cmake -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

# Clear build dirs
clean:
	rm -rf $(BUILD_DIR)

run: build
	$(EXECUTABLE)

