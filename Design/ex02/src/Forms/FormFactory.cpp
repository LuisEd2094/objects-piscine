#include <Forms/FormFactory.hpp>

Form *FormFactory::createForm(FormType p_formType)
{
    Form *form = nullptr;
    switch (p_formType)
    {
    case FormType::CourseFinished:
        form = new CourseFinishedForm(nullptr);
        break;
    case FormType::NeedMoreClassRoom:
        form = new NeedMoreClassRoomForm();
        break;
    case FormType::NeedCourseCreation:
        form = new NeedCourseCreationForm();
        break;
    case FormType::SubscriptionToCourse:
        form = new SubscriptionToCourseForm();
        break;
    default:
        throw std::invalid_argument("Invalid form type");
    }
    std::cout << "Form created from form Factory: " << *form << std::endl;
    return form;
}

