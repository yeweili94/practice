#include <vector>
#include <iostream>
using namespace std;

vector<int> findrange(const vector<int>& nums, int a, int b) {
    int size = nums.size();
    vector<int> ret;
    if (size <= 0) return ret;
    int low = 0, high = size - 1;
    int posa = -1, posb = -1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= a) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    if (posa == -1) {
        posa = low;
    }

    high = size - 1;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (nums[mid] >= b) {
            high = mid - 1;
        }
        else {
            low = mid;
        }
    }
    if (posb == -1) {
        posb = low;
    }
    if (nums[posa] > a || nums[posb] <= b) {
        return ret;
    }
    for (int i = posa; i <= posb; i++) {
        ret.push_back(nums[i]);
    }
    return ret;
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 6, 8, 8, 8, 8, 8, 10};
    vector<int> target = findrange(nums, -1, 0);
    for (int elem : target) {
        cout << elem << " ";
    }
    cout << endl;
}
