#include <Forms/FormCommander.hpp>
#include <Forms/Form.hpp>

/*Centralizing execution in this class allows us to expand on the execution processes
If in the future we need to change how the execution is handled, maybe we need to log it or something
we can do it here and it will be applied to all forms.
Likewise, we can easily control who gets to execute forms by making them friends of this class,
as we did with Headmaster. This way, any future class that may have form execution rights will be able to do so
without having to change the Form class, and they will always have the same execution process.

We use nested classes to give even more control over who has access to what. If we want secretary to be able to sign forms
but not to execute them, then we can make Secretary a friend of FormSigner but not of FormExecutor.
*/

void FormCommander::FormExecutor::execute(Form &form)
{
    std::cout << "Executing Form" << std::endl;
    form.execute();
}
void FormCommander::FormSigner::sign(Form &form)
{
    std::cout << "Signing form" << std::endl;
    form.sign();
}