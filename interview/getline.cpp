#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;

int main()
{
    char str[10];
    scanf("%s", str);
    printf("%s\n", str);
    int len = strlen(str);
    assert(str[len] == '\0');
    (void)len;
    // stringstream ss(str);
    // string temp;
    // while (getline(ss, temp, ',')) {
    //     cout << temp << " ";
    // }
}
