#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (m == 0 || n == 0) {
        if (m == 0 && n != 0) {
            return -1;
        }
        return 0;
    }
    int next[n];
    get_next(next, needle);
    cout << "next: ";
    for (int i = 0; i < n; i++) {
        cout << next[i] << " ";
    }
    cout << endl;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == n) {
        return i - j;
    } else {
        return -1;
    }
}

void get_next(int next[], const string &needle) {
    next[0] = -1;
    int size = needle.size();
    int i = 0, j = -1;
    while (i < size) {
        if (j == -1 || needle[i] == needle[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
};

int main()
{
    Solution s;
    string str1 = "12324323422332";
    string str2 = "abcabd";
    cout << s.strStr(str1, str2) << endl;
    return 1;
}
