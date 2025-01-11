#ifndef FORM_HPP
#define FORM_HPP

#include <enums.hpp>
#include <Course.hpp>
#include <iostream>
class Form
{
private:
	FormType _formType;
	void sign()
	{
		std::cout << "Form signed" << std::endl;
		_isSigned = true;
	}
	void execute()
	{
		if (_isSigned)
		{
			onExectute();
		}
	}

protected:
	bool _isSigned;
	virtual void onExectute() = 0;

public:
	Form(FormType p_formType) : _formType(p_formType), _isSigned(false)
	{
	}

	friend class Headmaster;
};

#include <Forms/CourseFinishedForm.hpp>
#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Forms/NeedCourseCreationForm.hpp>
#include <Forms/SubscriptionToCourseForm.hpp>

#endif
