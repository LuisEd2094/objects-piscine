#include <iostream>
#include <All.hpp>

void testFormCreation()
{
    std::cout << "Testing form creation" << std::endl;
    Secretary secretary("Secretary");
    Course  course("Physics");
    Student student("John");
    Form *form;
    for (int i = 0; i < static_cast<int>(FormType::COUNT); i++)
    {
        if (i == static_cast<int>(FormType::CourseFinished))
        {
            Course course = Course("Math");
            form = secretary.createForm(FormType::CourseFinished, &course);
        }
        else if (i == static_cast<int>(FormType::NeedCourseCreation))
        {
            form = secretary.createForm(FormType::NeedCourseCreation, std::string("Math"));
        }
        else if (i == static_cast<int>(FormType::SubscriptionToCourse))
        {

            form = secretary.createForm(FormType::SubscriptionToCourse, &course, &student);
        }
        else
        {
            form = secretary.createForm(static_cast<FormType>(i));
        }
        std::cout << "Secretary created form: " << *form << std::endl;
        delete form;
    }
}

void testFormSign()
{
    std::cout << "Testing form sign" << std::endl;
    Secretary secretary("Secretary");
    Headmaster headmaster = Singleton<Headmaster>::getInstance();
    Course course("Physics");
    Form *form = secretary.createForm(FormType::CourseFinished, &course);
    std::cout << "Secretary created form: " << *form << std::endl;
    headmaster.signForm(form);

    delete form;
}

void testFormExecute()
{
    std::cout << "Testing form execute" << std::endl;
    Secretary secretary("Secretary");
    Headmaster headmaster = Singleton<Headmaster>::getInstance();
    Course course("Physics");
    Form *form = secretary.createForm(FormType::CourseFinished, &course);
    Form *form2 = secretary.createForm(FormType::NeedMoreClassRoom);

    std::cout << "Secretary created form: " << *form << std::endl;
    headmaster.signForm(form);
    headmaster.executeForm(form);
    headmaster.executeForm(form2);

    delete form;
}

void testRoomEnter()
{
    std::cout << "Testing room enter" << std::endl;
    RoomList roomList;
    std::cout << "Room size" << roomList.size() << std::endl;
    roomList.push_back(Classroom());
    std::cout << "Room size after adding classroom" << roomList.size() << std::endl;

    HeadmasterOffice headmasterOffice;
    Secretary secretary("Secretary");
    Professor professor("Professor");

    std::cout << "Can enter headmaster: " << headmasterOffice.canEnter(static_cast<Person *>(&Singleton<Headmaster>::getInstance())) << std::endl;
    std::cout << "Can enter secretary: " << headmasterOffice.canEnter(&secretary) << std::endl;
    std::cout << "Can enter professor: " << headmasterOffice.canEnter(&professor) << std::endl;
}

void testMediator()
{
    Headmaster headmaster = Singleton<Headmaster>::getInstance();
    Student student("John");
    Professor proffesor("Math");

    headmaster.registerMediatee(&student);
    headmaster.registerMediatee(&proffesor);
    headmaster.notify(&student, "Event", 1, 2, 3);
    headmaster.notify(&proffesor, "Event");
    
}

int main()
{
    std::cout << Singleton<Headmaster>::getInstance().getName();
    try
    {
        std::cout << "Starting tests" << std::endl;
        testRoomEnter();
        testFormCreation();
        testFormSign();
        testFormExecute();
        testMediator();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}