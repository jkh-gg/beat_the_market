CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -I./src
PROD_CXXFLAGS = -std=c++17 -Wall -O3 -DNDEBUG -I. -I./src
LDFLAGS =

BUILD_DIR := build
BIN_NAME := btm
TEST_BIN_NAME := run_tests

PROD_BIN_DIR := release
PROD_BIN_NAME := btm_release


# Source File Discovery
SRCS_BASE_DIR := src
APP_MAIN_SRC := app.cpp
LIB_SRCS := $(wildcard $(SRCS_BASE_DIR)/**/*.cpp)
LIB_SRCS := $(filter-out $(APP_MAIN_SRC), $(LIB_SRCS))

TEST_BASE_DIR := tests
TEST_MAIN_SRC := tests/test.cpp
INDIVIDUAL_TEST_SRCS := $(wildcard $(TEST_BASE_DIR)/**/*.cpp)
INDIVIDUAL_TEST_SRCS := $(filter-out $(TEST_MAIN_SRC), $(INDIVIDUAL_TEST_SRCS))


# Consolidated Source Lists
APP_ALL_SRCS := $(APP_MAIN_SRC) $(LIB_SRCS)
TEST_ALL_SRCS := $(TEST_MAIN_SRC) $(INDIVIDUAL_TEST_SRCS) $(LIB_SRCS)


# Object File Paths
APP_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(APP_ALL_SRCS))
TEST_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_ALL_SRCS))
PROD_APP_OBJS := $(patsubst %.cpp,$(PROD_BIN_DIR)/%.o,$(APP_ALL_SRCS))

.PHONY: all clean tests directories production_directories release


# Main Targets
all: directories $(BUILD_DIR)/$(BIN_NAME)
	@echo "Running..."
	@$(BUILD_DIR)/$(BIN_NAME)

release: production_directories $(PROD_BIN_DIR)/$(PROD_BIN_NAME)

tests: directories $(BUILD_DIR)/$(TEST_BIN_NAME)
	@echo "Running tests..."
	@$(BUILD_DIR)/$(TEST_BIN_NAME)

clean:
	@rm -rf $(BUILD_DIR) $(PROD_BIN_DIR)


# Directory Creation Rules
directories:
	@mkdir -p $(sort $(dir $(APP_OBJS) $(TEST_OBJS)))

production_directories:
	@mkdir -p $(sort $(dir $(PROD_APP_OBJS)))


# Build Rules
$(BUILD_DIR)/$(BIN_NAME): $(APP_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(TEST_BIN_NAME): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(PROD_BIN_DIR)/$(PROD_BIN_NAME): $(PROD_APP_OBJS)
	$(CXX) $(PROD_CXXFLAGS) $(LDFLAGS) -o $@ $^


# Implicit Rules for Object Files
$(BUILD_DIR)/%.o: %.cpp | directories
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PROD_BIN_DIR)/%.o: %.cpp | production_directories
	$(CXX) $(PROD_CXXFLAGS) -c $< -o $@