# Selinie Wang (jw6qe@virginia.edu)
# October 23, 2018
# Makefile

CXX=clang++ 
CXXFLAGS=-Wall -std=c++11

OFILES = hashTable.o wordPuzzle.o timer.o

Lab06: $(OFILES)
		$(CXX) $(DEBUG) $(OFILES)
		@echo "Lab06 is Hot and Ready!"

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -O2 -c hashTable.cpp

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -O2 -c wordPuzzle.cpp

timer.o: timer.cpp timer.h
	$(CXX) -O2 -c timer.cpp

.SUFFIXES: .o .cpp

clean:
	-rm -f *.o *~