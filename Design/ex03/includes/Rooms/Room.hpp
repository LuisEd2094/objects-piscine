#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <List.hpp>
#include <typeinfo>
#include <typeindex>

class Person;
class Room
{
private:
	static long long ID;
	List<Person *> _occupants;
	List<std::type_index> _allowedOccupants;

public:
	Room();
	template <typename... Args>
	Room(Args... types);

	~Room();
	bool canEnter(Person *);
	void enter(Person *);
	void exit(Person *);
	void printOccupant();
};

#include <Rooms/Room.tpp>


#endif
