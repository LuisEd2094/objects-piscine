#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex> // For thread-safety (C++11 and above)

template <typename T>
class Singleton
{
private:
    Singleton() {}

    // Deleted copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T* instance;
    static std::mutex mutex_;
public:
    static T& getInstance()
    {
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (instance == nullptr)
            {
                instance = new T();
            }
        }
        return *instance;
    }
    ~Singleton()
    {
        if (instance != nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            delete instance;
            instance = nullptr;
        }
    }
};

template <typename T>
T* Singleton<T>::instance = nullptr;

template <typename T>
std::mutex Singleton<T>::mutex_;

#endif
