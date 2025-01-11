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

    static std::mutex mutex_;
public:
    static T& getInstance()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        static T instance; 
        return instance;
    }
    ~Singleton()
    {

    }
};


template <typename T>
std::mutex Singleton<T>::mutex_;

#endif
