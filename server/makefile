# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++17 \
           -Icode \
           -Icode/database \
           -Icode/file_io \
           -Icode/networking \
           -I/usr/include/enet \
           -I/usr/local/include/bsoncxx \
           -I/usr/local/include/mongocxx

# Linker Flags
LDFLAGS = -L/usr/local/lib

# Libraries
LDLIBS = -lenet -lbsoncxx -lmongocxx

# Source Directories
SRC_DIRS = code code/database code/file_io code/networking

# Automatically find all .cpp files in the specified directories
SOURCES := $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))

# Derive object files from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Target Executable
TARGET = server

# Default Rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS)
	rm -f $(OBJECTS)
# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Up
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
