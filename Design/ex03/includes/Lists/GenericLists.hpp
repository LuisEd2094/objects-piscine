#ifndef GENERIC_LISTS_HPP
#define GENERIC_LISTS_HPP

template <typename T>
class GenericLists
{
public:
    void push_back(const T &t);
    T const &operator[](int index) const;
    T &operator[](int index);
    size_t size() const;
};

#include <Lists/GenericLists.tpp>

#endif
