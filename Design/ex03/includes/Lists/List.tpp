#ifndef LIST_TPP
#define LIST_TPP

#include <Lists/List.hpp>
#include <Singleton.hpp>

template <typename T>
List<T>::List(const List &rhs)
{
    std::lock_guard<std::mutex> lock_rhs(rhs.mutex_);
    items = rhs.items;
};

template <typename T>
List<T> &List<T>::operator=(const List<T> &rhs)
{
    std::lock_guard<std::mutex> lock_rhs(rhs.mutex_);
    std::lock_guard<std::mutex> lock(this.mutex_);
    items = rhs.items;
};
template <typename T>
List<T>::List() {}
template <typename T>
List<T>::~List() {}
/** @brief Thread safe method to add an item to the list
 *
 */
template <typename T>
void List<T>::push_back(const T &item)
{
    std::lock_guard<std::mutex> lock(mutex_);
    items.push_back(item);
}

template <typename T>
void List<T>::push_back(const T *item)
{
    std::lock_guard<std::mutex> lock(mutex_);
    items.push_back(*item);
}

/**
 * @brief Thread safe method to remove the last item from the list
 */
template <typename T>
void List<T>::pop_back()
{
    std::lock_guard<std::mutex> lock(mutex_);
    items.pop_back();
}

/**
 * @brief Thread safe method to get the items, returns a const reference to the object
 */
template <typename T>
T const &List<T>::operator[](int index) const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items[index];
}

/**
 * @brief Thread safe method to get the items, reference to the object
 */
template <typename T>
T &List<T>::operator[](int index)
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items[index];
}
/**
 * @brief Thread safe method to get the items, returns a reference to the object
 */
template <typename T>
size_t List<T>::size() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.size();
}

// Iterator functions for range-based for loops and manual iteration
template <typename T>
typename std::vector<T>::iterator List<T>::begin()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.begin();
}
template <typename T>
bool List<T>::empty() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.empty();
}

template <typename T>
bool List<T>::contains(const T &item) const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return std::find(items.begin(), items.end(), item) != items.end();
}

template <typename T>
typename std::vector<T>::iterator List<T>::end()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.end();
}

template <typename T>
typename std::vector<T>::const_iterator List<T>::begin() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.begin();
}

template <typename T>
typename std::vector<T>::const_iterator List<T>::end() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.end();
}

template <typename T>
typename std::vector<T>::const_iterator List<T>::cbegin() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.cbegin();
}

template <typename T>
typename std::vector<T>::const_iterator List<T>::cend() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return items.cend();
}

template <typename T>
void List<T>::erase(const T &item)
{
    std::lock_guard<std::mutex> lock(mutex_);
    items.erase(std::find(items.begin(), items.end(), item));
}


#endif 
