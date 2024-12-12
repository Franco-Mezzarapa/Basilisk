# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++17 -I/usr/include/enet

# Linker Flags
LDFLAGS = -L/usr/local/lib -lenet

# Source Files
SOURCES = client.cpp networking/networking_client.cpp

# Object Files
OBJECTS = $(SOURCES:.cpp=.o)

# Output Executable
TARGET = client

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: clean
