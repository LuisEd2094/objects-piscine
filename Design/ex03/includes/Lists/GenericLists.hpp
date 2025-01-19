#ifndef GENERIC_LISTS_HPP
#define GENERIC_LISTS_HPP

#include <cstddef>
#include <Lists/List.hpp>
template <typename T>
class GenericLists : public List<T>
{
public:
    void push_back(const T &item);

    void push_back(const T *item);

    void pop_back();

    T const &operator[](int index) const;

    T &operator[](int index);

    size_t size() const;

    typename std::vector<T>::iterator begin();
    bool empty() const;
    void erase(const T &item);

    bool contains(const T &item) const;

    typename std::vector<T>::iterator find(const T &item);

    typename std::vector<T>::const_iterator find(const T &item) const;
    
    template <typename Predicate>
    typename std::vector<T>::iterator find_if(Predicate pred) const;

    template <typename Predicate>
    typename std::vector<T>::const_iterator find_if(Predicate pred) const;

    template <typename Predicate>
    T find_if(Predicate pred);

    typename std::vector<T>::iterator end();

    typename std::vector<T>::const_iterator begin() const;

    typename std::vector<T>::const_iterator end() const;

    typename std::vector<T>::const_iterator cbegin() const;

    typename std::vector<T>::const_iterator cend() const;
};

#include <Lists/GenericLists.tpp>

#endif
