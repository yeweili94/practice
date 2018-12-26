#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <utility>
#include <stdlib.h>
using namespace std;

string aminusb(const string& stra, const string& strb) {
    int sizea = stra.size(), sizeb = strb.size();
    vector<int> a(sizea, 0);
    vector<int> b(sizeb, 0);
    vector<int> ret(sizea, 0);
    for (int i = 0; i < sizea; i++) {
        a[i] = stra[i] - '0';
    }
    for (int i = 0; i < sizeb; i++) {
        b[i] = strb[i] - '0';
    }
    int i = sizea - 1, j = sizeb - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] >= b[j]) {
            ret[i] = a[i] - b[j];
        }
        else {
            int k = i - 1;
            while (k >= 0) {
                if (a[k] > 0) {
                    a[k]--;
                    break;
                }
                else {
                    a[k] += 9;
                }
                k--;
            }
            ret[i] = a[i] + 10 - b[j];
        }
        i--;
        j--;
    }
    while (i >= 0) {
        ret[i] = a[i];
        i--;
    }
    i = 0;
    while (i < sizea && ret[i] == 0) {
        i++;
    }
    if(i == sizea) return "0";
    stringstream ss;
    while (i < sizea) {
        ss << ret[i];
        i++;
    }
    return ss.str();
}

void test()
{
    int a = random() % 100002000;
    int b = random() % 230000000;
    if (b > a) swap(a, b);
    stringstream ss;
    string stra, strb;
    ss << a; ss >> stra;
    ss.ignore(); ss.clear();

    ss << b; ss >> strb;
    ss.ignore(); ss.clear();

    cout << a << " - " << b << " = " << aminusb(stra, strb) << endl;
    int trueans = a - b;
    int testans;
    ss << aminusb(stra, strb);
    ss >> testans;

    assert(trueans == testans);
}

int main()
{
    int i = 100000;
    while (i--) {
        test();
    }
}
