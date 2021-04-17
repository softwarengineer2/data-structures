CXX = g++
CPP_EXTENSION=cpp
C_EXTENSION=c
EXEC = main
LBLIBS = -lstdc++

BUILD_DIR = ./build
SRC_DIRS = ./src

SRCS := $(shell find $(SRC_DIRS) -name *.$(CPP_EXTENSION) -or -name *.$(C_EXTENSION))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXXFLAGS ?= -Werror -pedantic -std=c++17 -g -fsanitize=address
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

LDFLAGS =  -fsanitize=address

$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)  $(LBLIBS)

# c source
$(BUILD_DIR)/%.$(C_EXTENSION).o: %.$(C_EXTENSION)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.$(CPP_EXTENSION).o: %.$(CPP_EXTENSION)
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)/*

run: 
	$(BUILD_DIR)/$(EXEC)

all: clean $(BUILD_DIR)/$(EXEC) run

MKDIR_P ?= mkdir -p