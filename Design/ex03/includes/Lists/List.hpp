#ifndef LIST_HPP
#define LIST_HPP

#include <vector>
#include <memory>
#include <mutex>
#include <Singleton.hpp>
#include <functional>

template <typename T>
class List
{
private:
    std::vector<T> items;
    // Mutable because we want to return a shared pointer to a const vector
    mutable std::mutex mutex_;


public:
    List(const List &rhs)
    {
        std::lock_guard<std::mutex> lock_rhs(rhs.mutex_);
        items = rhs.items;
    };
    List &operator=(const List &rhs)
    {
        std::lock_guard<std::mutex> lock_rhs(rhs.mutex_);
        std::lock_guard<std::mutex> lock(this.mutex_);
        items = rhs.items;
    };
    List() {}
    ~List() {}
    /** @brief Thread safe method to add an item to the list
     *
     */
    void push_back(const T &item)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        items.push_back(item);
    }
    void push_back(const T *item)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        items.push_back(*item);
    }

    /**
     * @brief Thread safe method to remove the last item from the list
     */
    void pop_back()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        items.pop_back();
    }

    /**
     * @brief Thread safe method to get the items, returns a const reference to the object
     */
    T const &operator[](int index) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items[index];
    }

    /**
     * @brief Thread safe method to get the items, reference to the object
     */
    T &operator[](int index)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items[index];
    }
    /**
     * @brief Thread safe method to get the items, returns a reference to the object
     */
    size_t size() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.size();
    }

    // Iterator functions for range-based for loops and manual iteration
    typename std::vector<T>::iterator begin()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.begin();
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.empty();
    }

    bool contains(const T &item) const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return std::find(items.begin(), items.end(), item) != items.end();
    }

    typename std::vector<T>::iterator end()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.end();
    }

    typename std::vector<T>::const_iterator begin() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.begin();
    }

    typename std::vector<T>::const_iterator end() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.end();
    }

    typename std::vector<T>::const_iterator cbegin() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.cbegin();
    }

    typename std::vector<T>::const_iterator cend() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return items.cend();
    }

    friend class Course;

    template <typename U>
    friend class GenericLists; // Friend to access the non-const operator[]
};

#endif