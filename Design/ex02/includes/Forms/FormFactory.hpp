#ifndef FORMFACTORY_HPP
#define FORMFACTORY_HPP

#include <Forms/Form.hpp>
#include <Person/Headmaster.hpp>

class Secretary;
class FormFactory
{
private:
    friend class Secretary;
    FormFactory() = delete;
    static Form *createForm(FormType p_formType);
    template <typename... Args>
    static Form *createForm(FormType p_formType, Args &&...args)
    {
        Form *form = nullptr;
        switch (p_formType)
        {
        case FormType::CourseFinished:
            form = new CourseFinishedForm(std::forward<Args>(args)...); // Forward arguments for CourseFinishedForm
            break;
        default:
            throw std::invalid_argument("Invalid form type");
        }

        std::cout << "Form created from Form Factory: " << *form << std::endl;
        return form;
    }
};

#endif
