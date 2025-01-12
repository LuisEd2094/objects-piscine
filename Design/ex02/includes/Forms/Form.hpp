#ifndef FORM_HPP
#define FORM_HPP

#include <enums.hpp>
#include <Course.hpp>
#include <iostream>

class Form
{
private:
	FormType _formType;
	/* I only want Headmaster to be able to sign and execute forms */
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
	friend class FormCommander;


protected:
	bool _isSigned;
	virtual void onExectute() = 0;

public:
	Form(FormType p_formType) : _formType(p_formType), _isSigned(false)
	{
	}
	virtual ~Form() = default;

	friend std::ostream& operator<<(std::ostream& os, const Form& form) {
        os << "Form type: " << static_cast<int>(form._formType) << std::endl;
        return os;  // Return the ostream object for chaining
    }

};


// If you want all forms to be in the same file, you can include them here and then include this file
#include <Forms/CourseFinishedForm.hpp>
#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Forms/NeedCourseCreationForm.hpp>
#include <Forms/SubscriptionToCourseForm.hpp>
#endif
