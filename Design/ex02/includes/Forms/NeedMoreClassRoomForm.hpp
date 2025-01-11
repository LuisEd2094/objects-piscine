#ifndef NEEDMORECLASSROOMFORM_HPP
#define NEEDMORECLASSROOMFORM_HPP

#include <Forms/Form.hpp>

class NeedMoreClassRoomForm : public Form
{
private:
public:
	NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom) {};
	void onExectute()
	{
		std::cout << "NeedMoreClass form executed" << std::endl;
	};
};

#endif
