CXXFLAGS += --std=c++17
GTKFLAGS  = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`



main: parent.o person.o student.o main.o entrydialog.o mainwin.o *.h
	$(CXX) $(CXXFLAGS) parent.o person.o student.o main.o mainwin.o entrydialog.o $(GTKFLAGS) -o smart

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o




	
debug: CXXFLAGS += -g
debug: parent.o person.o student.o  main.o mainwin.o entrydialog.o *.h 
	$(CXX) $(CXXFLAGS)  main.o mainwin.o entrydialog.o parent.o person.o student.o -o smart_debug
	echo gdb ./smart_debug to debug.

clean:
	rm -f *.o *.gch a.out smart smart_debug