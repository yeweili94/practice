#include <boost/noncopyable.hpp>
#include <pthread.h>
#include <iostream>
using namespace std;

template<typename T>
class Singleton : boost::noncopyable
{
public:
    static T& instance()
    {
        pthread_once(&ponce_, &Singleton::init);
        return *value_;
    }
    Singleton() = delete;
    ~Singleton() = delete;
private:
    static void init()
    {
        value_ = new T();
        ::atexit(destroy);
    }

    static void destroy()
    {
        delete value_;
    }
private:
    static pthread_once_t ponce_;
    static T* value_;
};


template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = NULL;

class Test : boost::noncopyable
{
public:
    Test()
    {
        cout << "Test constructed" << std::endl;
    }

    ~Test()
    {
        cout << "Test destroyed" << std::endl;
    }

    const string& name() const {return name_;}
    void setName(const string& name) {name_ = name; }
    void printName() {cout << name_ << endl;}

private:
    string name_;
};


int main()
{
    Singleton<Test>::instance().setName("hello world");
    Singleton<Test>::instance().printName();
    return 1;

}

