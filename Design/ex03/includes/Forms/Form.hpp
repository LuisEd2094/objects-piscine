#ifndef FORM_HPP
#define FORM_HPP

#include <enums.hpp>
#include <iostream>

class Form
{
private:
	FormType _formType;
	/* I only want Headmaster to be able to sign and execute forms */
	void sign();
	void execute();
	friend class FormCommander;

protected:
	bool _isSigned;
	virtual void onExectute() = 0;

public:
	Form(FormType p_formType);
	virtual ~Form() = default;

	friend std::ostream &operator<<(std::ostream &os, const Form &form)
	{
		os << "Form type: " << static_cast<int>(form._formType) << std::endl;
		return os; // Return the ostream object for chaining
	}
};

#endif
