#include <pthread.h>
#include <stdlib.h> //::atexit
#include <boost/noncopyable.hpp>
#include <pthread.h>

pthread_mutex_t mutex_ = PTHREAD_MUTEX_INITIALIZER;

template<typename T>
class SingleTon : public boost::noncopyable
{
public:
    static T& instance()
    {
        if (value_ == NULL) {
            pthread_mutex_lock(&mutex_);
            if (value_ == NULL) {
                value_ = new T();
                ::atexit(SingleTon::destroy);
            }
            pthread_mutex_unlock(&mutex_);
        }
        return *value_;
    }

private:
    SingleTon() = delete;
    ~SingleTon() = delete;

    static void destroy()
    {
        delete value_;
    }

    static T* value_;
};

template<typename T>
T* SingleTon<T>::value_ = NULL;
