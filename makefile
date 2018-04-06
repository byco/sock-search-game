
output: main.o Bathroom.o Bedroom.o Closet.o Kitchen.o Lounge.o Menu.o Player.o Space.o WashingRoom.o
	g++ -g -std=c++0x main.o Bathroom.o Bedroom.o Closet.o Kitchen.o Lounge.o Menu.o Player.o Space.o WashingRoom.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp	

Bathroom.o: Bathroom.cpp Bathroom.hpp
	g++ -std=c++0x -c Bathroom.cpp	

Bedroom.o: Bedroom.cpp Bedroom.hpp
	g++ -std=c++0x -c Bedroom.cpp	

Closet.o: Closet.cpp Closet.hpp
	g++ -std=c++0x -c Closet.cpp	

Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -std=c++0x -c Kitchen.cpp	

Lounge.o: Lounge.cpp Lounge.hpp
	g++ -std=c++0x -c Lounge.cpp	

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++0x -c Player.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++0x -c Space.cpp

WashingRoom.o: WashingRoom.cpp WashingRoom.hpp
	g++ -std=c++0x -c WashingRoom.cpp

clean:
	rm *.o output