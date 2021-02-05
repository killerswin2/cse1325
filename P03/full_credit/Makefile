CXXFLAGS += -std=c++17

fraction: fraction.o main.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main.o -o fraction

fraction.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
clean:
	rm -f *.o *.gch a.out fraction 
