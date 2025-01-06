#ifndef LIST_HPP
#define LIST_HPP

#include <vector>

template <typename T>
class List
{
private:
    std::vector<T> items;

    List() {}
    List(const List &) = delete;
    List &operator=(const List &) = delete;

public:
    void addItem(const T &item)
    {
        items.push_back(item);
    }

    const std::vector<T> &getItems() const
    {
        return items;
    }
    friend class Singleton<List<T>>;
};

#endif
