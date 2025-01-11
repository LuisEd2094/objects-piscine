#ifndef LIST_HPP
#define LIST_HPP

#include <vector>
#include <memory>
#include <mutex>
#include <Singleton.hpp>

template <typename T>
class List
{
private:
    std::vector<T> items;
    // Mutable because we want to return a shared pointer to a const vector
    mutable std::mutex mutex_;
    List(const List &) = delete;
    List &operator=(const List &) = delete;


public:
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
};

#endif
