#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct point
{
    point(int a, int b) : x(a), y(b) {}
    int x;
    int y;
    // bool operator< (const point& that) {
    //     return y < that.y;
    // }
};

bool cmp(const point& a, const point& b) {
    if (a.x < b.x) return true;
    if (a.x == b.x) return a.y < b.y;
    return false;
}

struct cmpobj
{
    bool operator() (const point& lt, const point& rt) 
    {
        return lt.x < rt.x || (!(rt.x < lt.x) && lt.y < rt.y);
    }
};

int main()
{
    vector<point> vec;
    set<point,cmpobj> set;
    vec.push_back(point(1, 2));
    vec.push_back(point(1, 3));
    vec.push_back(point(2, 2));
    ///////////////////////////
    set.insert(point(1, 2));
    set.insert(point(1, 3));
    set.insert(point(2, 2));

    sort(vec.begin(), vec.end(), cmpobj());
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i].x << " : " << vec[i].y << std::endl;
    }
}
