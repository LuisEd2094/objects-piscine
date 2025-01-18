#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Rooms/Classroom.hpp>

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {};
void NeedMoreClassRoomForm::onExectute()
{
    Singleton<RoomList>::getInstance().push_back(Classroom());
    std::cout << "NeedMoreClass form executed" << std::endl;
};
NeedMoreClassRoomForm::~NeedMoreClassRoomForm(){};