#ifndef LIST_HPP
#define LIST_HPP

#include <vector>
#include <memory>
#include <mutex>
#include <functional>

template <typename T>
class List
{
private:
    std::vector<T> items;
    // Mutable because we want to return a shared pointer to a const vector
    mutable std::mutex mutex_;

public:
    List(const List &rhs);
    
    List &operator=(const List &rhs);
    
    List();
    
    ~List();
    void push_back(const T &item);
    
    void push_back(const T *item);
    
    void pop_back();

    T const &operator[](int index) const;
    
    T &operator[](int index);
    
    size_t size() const;
    
    typename std::vector<T>::iterator begin();
    bool empty() const;

    bool contains(const T &item) const;

    typename std::vector<T>::iterator end();

    typename std::vector<T>::const_iterator begin() const;

    typename std::vector<T>::const_iterator end() const;

    typename std::vector<T>::const_iterator cbegin() const;

    typename std::vector<T>::const_iterator cend() const;

    friend class Course;

    template <typename U>
    friend class GenericLists; // Friend to access the non-const operator[]
};

#include <Lists/List.tpp>

#endif
