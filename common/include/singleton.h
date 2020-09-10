#pragma once

template <typename T>
class SINGLETON
{
    private:
        static T instance_;

    public:
        static T& getInstance(void) { return instance_; }
};

template <class T> T SINGLETON<T>::instance_;
