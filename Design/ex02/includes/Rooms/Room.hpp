#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <List.hpp>
#include <typeinfo>
#include <typeindex>

class Person;
class Course;
class Form;

class Room
{
private:
	static long long ID;
	List<Person *> _occupants;
	List<std::type_index> _allowedOccupants;

public:
	Room() { ++Room::ID; };
	template <typename... Args>
	Room(Args... types) : Room()
	{
		std::type_index typeArray[] = {types...};
		for (const auto &type : typeArray)
		{
			_allowedOccupants.push_back(type);
		}
	}
	bool canEnter(Person *p_person)
	{
		for (auto &type : _allowedOccupants)
		{
			if (std::type_index(typeid(*p_person)) == type)
			{
				return true;
			}
		}
		return false;
	};
	void enter(Person *);
	void exit(Person *);

	void printOccupant();
};

long long Room::ID = 0;

#include <Rooms/Classroom.hpp>
#include <Rooms/Courtyard.hpp>
#include <Rooms/HeadmasterOffice.hpp>
#include <Rooms/SecretarialOffice.hpp>
#include <Rooms/StaffRestRoom.hpp>

#endif
