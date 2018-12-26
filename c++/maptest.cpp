#include <map>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
typedef std::pair<std::string, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
    return lhs.second < rhs.second;
}

struct CmpByKeyLen
{
    bool operator()(const PAIR& lhs, const PAIR& rhs)
    {
        return lhs.second > rhs.second;
    }
};

struct MapCmp
{
    bool operator()(const string& lhs, const string& rhs)
    {
        return lhs.size() < rhs.size();
    }
};

int main()
{
    map<string, int, ::greater<string> > map;
    map["hello"] = 9;
    map["google"] = 3;
    map["world"] = 0;
    std::vector<PAIR> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), CmpByKeyLen());
    for (auto it = map.begin(); it != map.end(); it++) {
        std::cout << "[key:" << it->first << "] " << "[value:" << it->second <<"]" << std::endl;
    }
 }
