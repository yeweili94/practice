#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5, 6, 8};
    auto iter = lower_bound(nums.begin(), nums.end(), 7);
    if (iter == nums.end()) {
        std::cout << "not fount lower_bound of " << 7 << std::endl;
    } else {
        std::cout << "find lower_bound is " << *iter << std::endl;
    }
    auto up = upper_bound(nums.begin(), nums.end(), 7);
    if (up == nums.end()) {
        std::cout << "not fount upper_bound of " << 7 << std::endl;
    } else {
        std::cout << "find upper_bound is " << *up << std::endl;
    }
}
