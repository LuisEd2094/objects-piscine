#ifndef FORMFACTORY_HPP
#define FORMFACTORY_HPP

#include <Forms/Form.hpp>

class Secretary;
class FormFactory
{
private:
    friend class Secretary;
    FormFactory() = delete;

    template <typename... Args>
    static Form *createForm(FormType p_formType, Args &&...args);

    template <typename T, typename... Args>
    static std::enable_if_t<std::is_constructible<T, Args...>::value, T *>
    create(Args &&...args);

    template <typename T, typename... Args>
    static std::enable_if_t<!std::is_constructible<T, Args...>::value, T *>
    create(Args &&...);
};
#include <Forms/FormFactory.tpp>

#endif
