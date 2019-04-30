#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

struct topkcmp
{
    bool operator() (const pair<int,int>& lt, const pair<int,int>& rt)
    {
        if (lt.second > rt.second) return true;
        if (lt.second == rt.second) return lt.first < rt.first;
        return false;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ret;
    int size = nums.size();
    if (size <= 0) return ret;
    unordered_map<int,int> map;
    for (auto& elem : nums) {
        map[elem]++;
    }
    set<pair<int, int>, topkcmp> set_;
    for (auto it = map.begin(); it != map.end(); it++) {
        set_.insert(*it);
    }
	for (auto it = set_.begin(); it != set_.end(); it++) {
        ret.push_back(it->first);
        if ((int)ret.size() >= k) return ret;
	}
    return ret;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 2 ,2 ,3, 3, 4};
    vector<int> ans = topKFrequent(nums, 3);
    for (auto elem : ans) {
        std::cout << elem;
    }
    cout << endl;
}
