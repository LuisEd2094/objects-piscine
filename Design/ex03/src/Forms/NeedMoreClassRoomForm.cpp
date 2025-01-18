#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Rooms/ClassRoom.hpp>
#include <Lists/RoomList.hpp>
#include <Singleton.hpp>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {};
void NeedMoreClassRoomForm::onExectute()
{
    Singleton<RoomList>::getInstance().push_back(ClassRoom());
    std::cout << "NeedMoreClass form executed" << std::endl;
};
NeedMoreClassRoomForm::~NeedMoreClassRoomForm(){};