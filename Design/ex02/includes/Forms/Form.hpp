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
		_isSigned = true;
	}
	void execute()
	{
		// We make a basic check at the form level to see if it is signed
		// Inherited class may have more complex checks
		if (_isSigned)
		{
			std::cout << "Form Signed, executing" << std::endl;
			onExectute();
		}
		else
		{
			std::cout << "Form not signed, cannot execute" << std::endl;
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

#endif
