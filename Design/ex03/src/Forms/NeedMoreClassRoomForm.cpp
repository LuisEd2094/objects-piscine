#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Rooms/ClassRoom.hpp>
#include <Lists/RoomList.hpp>
#include <Singleton.hpp>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {};
void NeedMoreClassRoomForm::onExectute()
{
    RoomList roomList;
    roomList.push_back(new ClassRoom());
};
NeedMoreClassRoomForm::~NeedMoreClassRoomForm(){};