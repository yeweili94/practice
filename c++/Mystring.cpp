#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <utility>

class MyString
{
public:
    //默认构造函数
    MyString() {
        m_data = new char[1];
        *m_data = '\0';
    }

    //构造函数
    MyString(const char* str) {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }

    //拷贝构造函数
    MyString(const MyString& str) {
        if (&str != this) {
            m_data = new char[strlen(str.m_data) + 1];
            strcpy(m_data, str.m_data);
        }
    }

    //移动构造函数
    MyString(MyString&& str) {
        m_data = str.m_data;
        str.m_data = NULL;
        std::cout << "move constructed called" << std::endl;
    }

    //赋值运算符
    MyString operator= (const MyString& str) {
        if (this != &str) {
            assert(this->m_data != NULL);
            delete[] m_data;
            m_data = NULL;
            m_data = new char[strlen(str.m_data) + 1];
            strcpy(m_data, str.m_data);
        }
        return *this;
    }

    //移动赋值运算符
    MyString operator= (MyString&& str) {
        if (&str != this) {
            assert(m_data != NULL);
            delete[] m_data;
            m_data = str.m_data;
            str.m_data = NULL;
        }
        return *this;
    }

    //重载+
    MyString operator+ (const MyString& str) {
        MyString newstr;
        if (this->m_data == NULL) {
            newstr = str;
        }
        else if (str.m_data == NULL) {
            newstr = *this;
        }
        else {
            newstr.m_data = new char[strlen(this->m_data) + strlen(str.m_data) + 1];
            strcpy(newstr.m_data, this->m_data);
            strcat(newstr.m_data, str.m_data);
        }
        return newstr;
    }

    //析构函数
    ~MyString() {
        if (this->m_data != NULL) {
            delete[] m_data;
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const MyString& str);
private:
    char *m_data;
};

std::ostream& operator<< (std::ostream& os, const MyString& str) {
    if (str.m_data != NULL) {
        os << str.m_data;
    }
    return os;
}

int main()
{
    MyString str2("bytedance");
    MyString str3;
    std::cout << "str2 :" << str2 << std::endl;
    std::cout << "str3 :" << str3 << std::endl;
    //赋值运算符
    str3 = str2;
    std::cout << "after copy assignment str3 = str2" << std::endl;
    std::cout << "str2 :" << str2 << std::endl;
    std::cout << "str3 :" << str3 << std::endl;
    //移动构造函数
    MyString str4(std::move(str3));
    std::cout << "str3 :" << str3 << std::endl;
    std::cout << "str4 :" << str4 << std::endl;
    //移动赋值运算符
    MyString str5;
    str5  = std::move(str4);
    std::cout << "after move assignment str5 = std::move(str4)" << std::endl;
    std::cout << "str4 :" << str4 << std::endl;
    std::cout << "str5 :" << str5 << std::endl;
    //重载+
    MyString str6 = str2 + str5;
    std::cout << "str6 = str2 + str5 = : " << str6 << std::endl;
}
