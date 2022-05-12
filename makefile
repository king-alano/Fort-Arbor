CXX = g++
CXXFLAGS = -Wall

tester: Character.o Party.o CharNode.o Weapon.o tester.cpp
        $(CXX) $(CXXFLAGS) Character.o tester.cpp -o tester
Character.o: Weapon.o Character.h Character.cpp
        $(CXX) $(CXXFLAGS) -c Character.cpp
Party.o: CharNode.o Party.h Party.cpp
        $(CXX) $(CXXFLAGS) -c Party.cpp
CharNode.o: CharNode.cpp Character.o
        $(CXX) $(CXXFLAGS) -c CharNode.cpp
Weapon.o: Weapon.cpp
        $(CXX) $(CXXFLAGS) -c Weapon.cpp
test:
        ./tester
