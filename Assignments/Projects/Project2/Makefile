# this is a comment in a make file 
CXX = clang++
PROGRAM = main.exe
FLAGS = -c -g -Wall -std=c++17 -pedantic
CPPFILES = main.cpp

all:
	$(CXX) $(FLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)

# A clean rule clears for fresh compilation
# if windows: use 'del' instead of linux 'rm'
clean:
	del $(PROGRAM) *.o