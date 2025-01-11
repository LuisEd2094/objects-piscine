#include <iostream>
#include <Course.hpp>
#include <Forms/Form.hpp>
#include <Person/Staff.hpp>
#include <Lists/RoomList.hpp>
#include <Rooms/Room.hpp>

int main()
{
    RoomList roomList;

    std::cout << roomList.size() << std::endl;
    roomList.push_back(Classroom());
    std::cout << roomList.size() << std::endl;

    HeadmasterOffice headmasterOffice;
    Secretary secretary("Secretary");
    Headmaster headmaster("Headmaster");
    Professor professor("Professor");

    std::cout << headmasterOffice.canEnter(&headmaster) << std::endl;
    std::cout << headmasterOffice.canEnter(&secretary) << std::endl;
    std::cout << headmasterOffice.canEnter(&professor) << std::endl;

    return 0;
}