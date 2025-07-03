CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

# Source files (explicitly list app_main.cpp, then other .cpp files)
# Using `filter-out` to remove app_main.cpp from general source discovery
# This prevents app_main.cpp from being picked up by the wildcard in src/
APP_SRC = app.cpp
SRCS_EXCL_MAIN = $(filter-out $(APP_SRC), $(wildcard *.cpp) $(wildcard src/*.cpp))

# All application source files
ALL_APP_SRCS = $(APP_SRC) $(SRCS_EXCL_MAIN)

BUILD_DIR := build
BIN_NAME := btm

# All application object files for the main build
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(ALL_APP_SRCS))

# Library object files for tests (all app objects EXCEPT app_main.o)
# This is the crucial line for tests.
LIB_OBJS := $(filter-out $(BUILD_DIR)/$(APP_SRC:.cpp=.o),$(OBJS))

BIN := $(BUILD_DIR)/$(BIN_NAME)

# Define test building
TEST_CXXFLAGS = $(CXXFLAGS) -I./dependencies/doctest

TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/$(TEST_DIR)/%.o, $(TEST_SRCS))

TEST_EXE = $(BUILD_DIR)/test_run

# Define the name of the executable for production builds
PRD_CXXFLAGS = -std=c++17 -Wall -O3 -DNDEBUG -s -I.

DIST_DIR := dist
PRD_BIN_NAME := beat_the_market
PRD_BIN := $(DIST_DIR)/$(PRD_BIN_NAME)

# --- Build Rules ---

# Rule for building the main application executable
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building the test executable
# It links the test objects and the filtered application library objects.
$(TEST_EXE): $(TEST_OBJS) $(LIB_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(TEST_CXXFLAGS) $(TEST_OBJS) $(LIB_OBJS) -o $@

# Rule for compiling test source files into the build/tests directory
$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

# General rule for compiling ANY .cpp file into its corresponding .o file in BUILD_DIR
# This handles files from . and src/ by preserving their path structure under build/
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for production build
prd: $(PRD_BIN)

$(PRD_BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(PRD_CXXFLAGS) -o $@ $^


# --- Phony Targets ---

.PHONY: all clean test run prd

# Default target
all: $(BIN)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(DIST_DIR)

# Run tests
test: $(TEST_EXE)
	./$(TEST_EXE)

# Run main application
run: $(BIN)
	./$(BIN)