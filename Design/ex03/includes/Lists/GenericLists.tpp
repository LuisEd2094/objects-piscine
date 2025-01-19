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

template <typename T>
void GenericLists<T>::pop_back()
{
    Singleton<List<T>>::getInstance().pop_back();
}

template <typename T>
typename std::vector<T>::iterator GenericLists<T>::begin()
{
    return Singleton<List<T>>::getInstance().begin();
}
template <typename T>
bool GenericLists<T>::empty() const
{
    return Singleton<List<T>>::getInstance().empty();
}

template <typename T>
bool GenericLists<T>::contains(const T &item) const
{
    return Singleton<List<T>>::getInstance().contains(item);
}

template <typename T>
typename std::vector<T>::iterator GenericLists<T>::end()
{
    return Singleton<List<T>>::getInstance().end();
}

template <typename T>
typename std::vector<T>::const_iterator GenericLists<T>::begin() const
{
    return Singleton<List<T>>::getInstance().begin();
}

template <typename T>
typename std::vector<T>::const_iterator GenericLists<T>::end() const
{
    return Singleton<List<T>>::getInstance().end();
}

template <typename T>
typename std::vector<T>::const_iterator GenericLists<T>::cbegin() const
{
    return Singleton<List<T>>::getInstance().cbegin();
}

template <typename T>
typename std::vector<T>::const_iterator GenericLists<T>::cend() const
{
    return Singleton<List<T>>::getInstance().cend();
}

template <typename T>
void GenericLists<T>::erase(const T &item)
{
    Singleton<List<T>>::getInstance().erase(item);
}

#endif