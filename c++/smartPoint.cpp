#include <iostream>
#include <assert.h>

template<typename T>
class SmartPoint
{
public:
    SmartPoint() = delete;

    SmartPoint(T* value) : value_(value)
    {
        count_ = new size_t;
        assert(value != NULL);
        if (value_) {
            *count_ = 1;
        }
        else {
            *count_ = 0;
        }
    }

    SmartPoint(const SmartPoint& p)
    {
        value_ = p.value_;
        count_ = p.count_;
        (*count_)++;
    }

    void operator= (const SmartPoint& p)
    {
        value_ = p.value_;
        (*count_)++;
    }

    ~SmartPoint()
    {
        if (--(*count_) == 0) {
            delete value_;
            delete count_;
        }
    }

    int count()
    {
        return *count_;
    }

private:
    T* value_;
    size_t* count_;
};

class Test
{
public:
    Test()
    {
        std::cout << "Test constructed" << std::endl;
    }
    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};


int main()
{
    SmartPoint<Test> p(new Test());
    std::cout << p.count() << std::endl;
    {
        SmartPoint<Test> p1(p);
        std::cout << p1.count() << std::endl;
    }
    std::cout << p.count() << std::endl;
}
