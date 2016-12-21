CXX = g++
# CXX = clang++ # has better error messages

CFLAGS = -c -Wall 


all: prog2 
	

prog2: main.o unionFind.o
	$(CXX) $^ -o $@
	
	
main.o: main.cpp 
	$(CXX) $(CFLAGS) main.cpp 
	
unionFind.o: unionFind.cpp 
	$(CXX) $(CFLAGS) unionFind.cpp 
	
	
clean:
	rm *o prog2