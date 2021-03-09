CXXFLAGS += --std=c++17



main: example.o parent.o person.o student.o *.h
	$(CXX) $(CXXFLAGS) example.o parent.o person.o student.o -o smart

example.o: example.cpp *.h
	$(CXX) $(CXXFLAGS) -c example.cpp -o example.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

	
debug: CXXFLAGS += -g
debug: example.o parent.o person.o student.o *.h 
	$(CXX) $(CXXFLAGS) example.o parent.o person.o student.o -o smart_debug
	echo gdb smart_debug to debug.

clean:
	rm -f *.o *.gch a.out smart smart_debug