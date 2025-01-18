#ifndef FORMCOMMANDER_HPP
#define FORMCOMMANDER_HPP

#include <Forms/Form.hpp>

class Headmaster;
class Form;

class FormCommander
{
public:
    class FormExecutor
    {
        friend class Headmaster;

        static void execute(Form &form);
    };
    class FormSigner
    {
        friend class Headmaster;

        static void sign(Form &form);
    };
};

#endif
