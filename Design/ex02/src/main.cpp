#include <iostream>
#include <Course.hpp>
#include <Forms/Form.hpp>
#include <Person/Staff.hpp>
#include <Lists/RoomList.hpp>
#include <Rooms/Room.hpp>


void testFormCreation()
{
    std::cout << "Testing form creation" << std::endl;
    Secretary secretary("Secretary");
    for (int i = 0; i < static_cast<int>(FormType::COUNT); i++)
    {
        Form* form = secretary.createForm(static_cast<FormType>(i));
        std::cout << "Secretary created form: " << *form << std::endl;
        delete form;
    }
}


void testRoomEnter()
{
    std::cout << "Testing room enter" << std::endl;
    RoomList roomList;
    std::cout << "Room size" << roomList.size() << std::endl;
    roomList.push_back(Classroom());
    std::cout << "Room size after adding classroom" << roomList.size() << std::endl;

    HeadmasterOffice headmasterOffice;
    Secretary secretary("Secretary");
    Headmaster headmaster("Headmaster");
    Professor professor("Professor");

    std::cout << "Can enter headmaster: " << headmasterOffice.canEnter(&headmaster) << std::endl;
    std::cout << "Can enter secretary: " << headmasterOffice.canEnter(&secretary) << std::endl;
    std::cout << "Can enter professor: " << headmasterOffice.canEnter(&professor) << std::endl;

}

int main()
{
    testRoomEnter();
    testFormCreation();
/*     testFormSign();
    testFormExecute(); */
    return 0;
}