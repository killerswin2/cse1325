CXXFLAGS += -std=c++17

fraction: fraction.o main.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main.o -o fraction
	echo ./fraction to begin

fraction.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test
	echo ./test for test

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
	
clean:
	rm -f *.o *.gch a.out fraction 
