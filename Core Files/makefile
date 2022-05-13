CXX = g++
CXXFLAGS = -Wall

tester: World.o Character.o Party.o Player.o CharNode.o Weapon.o tester.cpp
        $(CXX) $(CXXFLAGS) Character.o tester.cpp -o tester
Character.o: Weapon.o Character.h Character.cpp
        $(CXX) $(CXXFLAGS) -c Character.cpp
Party.o: CharNode.o Party.h Party.cpp
        $(CXX) $(CXXFLAGS) -c Party.cpp
CharNode.o: CharNode.cpp Character.o
        $(CXX) $(CXXFLAGS) -c CharNode.cpp
Weapon.o: Weapon.cpp
        $(CXX) $(CXXFLAGS) -c Weapon.cpp
World.o: Item.o Party.o Character.o World.cpp World.h
        $(CXX) $(CXXFLAGS) -c World.cpp
Item.o: Item.cpp
        $(CXX) $(CXXFLAGS) -c Item.cpp
Player.o: Character.o Player.cpp Player.h
        $(CXX) $(CXXFLAGS) -c Player.cpp
test:
        ./tester

