#ifndef FORMCOMMANDER_HPP
#define FORMCOMMANDER_HPP

#include <Forms/Form.hpp>
#include <Person/Headmaster.hpp>

class FormCommander
{
    friend class Headmaster;
    /*Centralizing execution in this class allows us to expand on the execution processes
        If in the futuro we need to change how the execution is handled, maybe we need to log it or something
        we can do it here and it will be applied to all forms.
        Likewise, we can easily control who gets to execute forms by making them friends of this class,
        as we did with Headmaster. This way, any future class that may have form execution rights will be able to do so
        without having to change the Form class, and they will always have the same execution process.
    */
    static void execute(Form &form)
    {
        form.execute();
    }
    static void sign(Form &form)
    {
        form.sign();
    }
};

#endif
