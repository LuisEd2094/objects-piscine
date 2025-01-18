#include <Forms/Form.hpp>

/* I only want Headmaster to be able to sign and execute forms */
void Form::sign()
{
    _isSigned = true;
}
void Form::execute()
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

Form::Form(FormType p_formType) : _formType(p_formType),
                                  _isSigned(false)
{
}
