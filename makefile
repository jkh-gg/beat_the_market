CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I./src
PROD_CXXFLAGS = -std=c++17 -Wall -O3 -DNDEBUG -I. -I./src
LDFLAGS =

BUILD_DIR := build
BIN_NAME := btm
TEST_BIN_NAME := run_tests

PROD_BIN_DIR := release
PROD_BIN_NAME := btm_release

APP_SRCS := app.cpp src/ui/ui.cpp
TEST_SRCS := tests/test.cpp

# Pattern substitution for object files in the build directory
APP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(APP_SRCS))
TEST_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))
LIB_OBJS := $(filter-out $(BUILD_DIR)/app.o,$(APP_OBJS))

# Pattern substitution for object files in the production directory
PROD_APP_OBJS := $(patsubst %.cpp,$(PROD_BIN_DIR)/%.o,$(APP_SRCS))

.PHONY: all clean tests directories production_directories release

# --- Main Targets ---

all: directories $(BUILD_DIR)/$(BIN_NAME)
	@echo "Running..."
	@$(BUILD_DIR)/$(BIN_NAME)

release: production_directories $(PROD_BIN_DIR)/$(PROD_BIN_NAME)

tests: directories $(BUILD_DIR)/$(TEST_BIN_NAME)
	@echo "Running tests..."
	@$(BUILD_DIR)/$(TEST_BIN_NAME)

clean:
	@rm -rf $(BUILD_DIR) $(PROD_BIN_DIR)

# --- Directory Creation Rules ---

# Rule to create build directories
directories:
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/src/ui $(BUILD_DIR)/tests

# Rule to create production directories
production_directories:
	@mkdir -p $(PROD_BIN_DIR) $(PROD_BIN_DIR)/src/ui $(PROD_BIN_DIR)/tests

# --- Build Rules ---

# Rule for building the main application in debug mode
$(BUILD_DIR)/$(BIN_NAME): $(APP_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Rule for building the test executable
$(BUILD_DIR)/$(TEST_BIN_NAME): $(TEST_OBJ) $(LIB_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Rule for building the production release
$(PROD_BIN_DIR)/$(PROD_BIN_NAME): $(PROD_APP_OBJS)
	$(CXX) $(PROD_CXXFLAGS) $(LDFLAGS) -o $@ $^

# --- Implicit Rules for Object Files ---

# Implicit rule for compiling source files into debug object files
$(BUILD_DIR)/%.o: %.cpp | directories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Implicit rule for compiling source files into production object files
$(PROD_BIN_DIR)/%.o: %.cpp | production_directories
	$(CXX) $(PROD_CXXFLAGS) -c $< -o $@