CXX = clang++
CPP = main.cpp
FLAGS = -c -g -Wall -std=c++17 -pedantic
PROGRAM = main.exe

#2-step build: produces object (.o) files for each cpp file 
#for large projects with lots of files this can save time
#can combine into one line
#$(cxx) $(CPP) $(FLAGS) -o $(PROGRAM)
build:
	$(CXX) $(CPP) $(FLAGS) 
	$(CXX) -o $(PROGRAM) *.o

#rm for linux or gitbash, del for windows
clean:
	del $(PROGRAM) *.object
test:
	$(PROGRAM) test

#kattis_test:
#cat 1.in > $(PROGRAM) > diff1.ans
run:
	./$(PROGRAM)

all: build test clean build run clean
	@echo "All done!"