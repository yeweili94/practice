#include <iostream>
#include <string>
#include <utility>

template<class T>
void swap(T& a, T& b)
{
    T c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}

void reverse(std::string& str, int start, int end) 
{
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void reverseworld(std::string& str) {
    int size = str.size();
    if (size <= 0) {
        return;
    }
    reverse(str, 0, size - 1);
    int low = 0, high = 0;
    while (low < size - 1) {
        if (str[low] == ' ' && str[high] == ' ') {
            low++;
            high++;
        } else if (high == size || str[high] == ' ') {
            high--;
            reverse(str, low, high);
            low = ++high;
        } else {
            high++;
        }
    }
}

int main()
{
    std::string str = " the sky is bule ";
    std::cout << "before reverse: " << str << std::endl;
    reverseworld(str);
    std::cout << "after  reverse: " << str << std::endl;
}
