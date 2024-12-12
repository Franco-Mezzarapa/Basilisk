# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++17 -I/usr/include/enet

# Linker Flags
LDFLAGS = -L/usr/local/lib

# Libraries
LDLIBS = -lenet

# Directories containing source files
SRC_DIRS = code code/networking code/file_io

# Automatically find all .cpp files in the specified directories
SOURCES := $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))

# Derive object files from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Target Executable
TARGET = server

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
