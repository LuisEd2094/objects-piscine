#ifndef NEEDMORECLASSROOMFORM_HPP
#define NEEDMORECLASSROOMFORM_HPP

#include <Forms/Form.hpp>
#include <Rooms/Classroom.hpp>
#include <Lists/RoomList.hpp>
class NeedMoreClassRoomForm : public Form
{
private:
public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {};
	void onExectute()
	{
		Singleton<RoomList>::getInstance().push_back(Classroom());
		std::cout << "NeedMoreClass form executed" << std::endl;
	};
	~NeedMoreClassRoomForm(){};
};

#endif
