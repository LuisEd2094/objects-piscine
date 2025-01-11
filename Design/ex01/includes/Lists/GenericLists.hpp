#ifndef GENERIC_LISTS_HPP
#define GENERIC_LISTS_HPP

#include <List.hpp> 


template <typename T>
class GenericLists {
public:
    void push_back(const T &t)
    {
        Singleton<List<T>>::getInstance().push_back(t);
    }

    T const &operator[](int index) const
    {
        return Singleton<List<T>>::getInstance()[index];
    }

    T  &operator[](int index)
    {
        return Singleton<List<T>>::getInstance()[index];
    }
    size_t size() const
    {
        return Singleton<List<T>>::getInstance().size();
    }

};

#endif
