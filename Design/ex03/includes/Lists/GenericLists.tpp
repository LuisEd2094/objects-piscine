#ifndef GENERIC_LISTS_TPP
#define GENERIC_LISTS_TPP

#include <Lists/GenericLists.hpp>
#include <Lists/List.hpp>
#include <Singleton.hpp>

template <typename T>
void GenericLists<T>::push_back(const T &t)
{
    Singleton<List<T>>::getInstance().push_back(t);
}

template <typename T>
size_t GenericLists<T>::size() const
{
    return Singleton<List<T>>::getInstance().size();
}

template <typename T>
T const &GenericLists<T>::operator[](int index) const
{
    return Singleton<List<T>>::getInstance()[index];
}

template <typename T>
T &GenericLists<T>::operator[](int index)
{
    return Singleton<List<T>>::getInstance()[index];
}

#endif