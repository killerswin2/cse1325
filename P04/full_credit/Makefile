GXXFLAGS += --std=c++17

Main: main.o deck.o card.o *.h
	$(CXX) $(GXXFLAGS) main.o deck.o card.o -o card
	
main.o: main.cpp *.h
	$(CXX) $(GXXFLAGS) -c main.cpp -o main.o
	 
deck.o: deck.cpp *.h
	$(CXX) $(GXXFLAGS) -c deck.cpp -o deck.o
	
card.o: card.cpp *.h
	$(CXX) $(GXXFLAGS) -c card.cpp -o card.o

clean:
	rm -f main.o deck.o card.o *.gch .a.out 

debug:	main.o deck.o card.o *.h
	$(CXX) $(GXXFLAGS) -g main.o deck.o card.o -o card_debug
