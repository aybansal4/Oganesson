# I do not know how to make a Makefile, this one was completely AI generated, I will try to make my own soon.


# 1. Variables for Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g -I/opt/homebrew/include -std=c++26

# 2. Target Executable Name and Object Files
# Change 'my_program' to whatever you want your final executable to be named
TARGET = Oganesson
OBJS = oganesson.o

# 3. Default Rule to build the executable
all: $(TARGET)

# Rule to link the object file into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 4. Specific rule to compile main.cpp into oganesson.o
oganesson.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o oganesson.o

# 5. Clean rule to delete all object files and the final executable
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
