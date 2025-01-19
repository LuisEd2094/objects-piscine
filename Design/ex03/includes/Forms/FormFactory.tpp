#ifndef FORMFACTORY_TPP
#define FORMFACTORY_TPP
#include <Forms/FormFactory.hpp>
#include <Forms/CourseFinishedForm.hpp>
#include <Forms/NeedCourseCreationForm.hpp>
#include <Forms/SubscriptionToCourseForm.hpp>
#include <Forms/NeedMoreClassRoomForm.hpp>
#include <Forms/AssignProfessorToCourse.hpp>

template <typename... Args>
Form *FormFactory::createForm(FormType p_formType, Args &&...args)
{
    Form *form = nullptr;
    switch (p_formType)
    {
    case FormType::CourseFinished:
        form = create<CourseFinishedForm>(std::forward<Args>(args)...); // Forward arguments for CourseFinishedForm
        break;
    case FormType::NeedCourseCreation:
        form = create<NeedCourseCreationForm>(std::forward<Args>(args)...); // Forward arguments for NeedCourseCreationForm
        break;
    case FormType::SubscriptionToCourse:
        form = create<SubscriptionToCourseForm>(std::forward<Args>(args)...); // Forward arguments for SubscriptionToCourseForm
        break;
    case FormType::NeedMoreClassRoom:
        form = create<NeedMoreClassRoomForm>(std::forward<Args>(args)...); // Forward arguments for SubscriptionToCourseForm
        break;
    case FormType::AssignProfessorToCourse:
        form = create<AssignProfessorToCourse>(std::forward<Args>(args)...); // Forward arguments for SubscriptionToCourseForm
        break;
    default:
        throw std::invalid_argument("Invalid form type");
    }
    if (form == nullptr)
    {
        throw std::invalid_argument("Invalid form arguments");
    }
    std::cout << "Form created from Form Factory: " << *form << std::endl;
    return form;
}

/*  https://stackoverflow.com/questions/28256550/factory-pattern-using-variadic-template
    SFINAE: Substitution Failure Is Not An Error
    We can use enable_if to enable or disable a function based on a condition.
    if you can construct the object with the arguments, then the function is enabled, otherwise it returns a null pointer.
    We do this to be able to compile. Compilers will check  something like this:
            if (i == static_cast<int>(FormType::CourseFinished))
    {
        Course course = Course("Math");
        form = secretary.createForm(FormType::CourseFinished, &course);
    }
    else if (i == static_cast<int>(FormType::NeedCourseCreation))
    {
        form = secretary.createForm(FormType::NeedCourseCreation, std::string("Math"));
    }
    and I'd try to create NeedMoreClassRoomForm with a course (because one of the possible creations uses Course *), which is not possible.
    We now CAN create a needMoreClassRoomForm with a course, but it will return a nullpointer. There won't be an error, but have to check it now.
    With this, we are now able to use our factory to create any form we want, with any arguments we want.
     */
template <typename T, typename... Args>
std::enable_if_t<std::is_constructible<T, Args...>::value, T *>
FormFactory::create(Args &&...args)
{
    return new T(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
std::enable_if_t<!std::is_constructible<T, Args...>::value, T *>
FormFactory::create(Args &&...)
{
    return nullptr;
}

#endif