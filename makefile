CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

# Add more source directories here
SRC_DIRS := .
SRCS := $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS)))

BUILD_DIR := build
BIN_NAME := btm
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

BIN := $(BUILD_DIR)/$(BIN_NAME)

# Define the name of the executable for production builds
PRD_CXXFLAGS = -std=c++17 -Wall -O3 -DNDEBUG -s -I.

DIST_DIR := dist
PRD_BIN_NAME := beat_the_market
PRD_BIN := $(DIST_DIR)/$(PRD_BIN_NAME)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

prd: $(PRD_BIN)

$(PRD_BIN): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(PRD_CXXFLAGS) -o $@ $^

build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(DIST_DIR)

run: $(BIN)
	./$(BIN)