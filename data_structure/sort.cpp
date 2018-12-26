#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <assert.h>
using namespace std;

namespace ShellSort{
void sort(vector<int>& nums) {
    int size = nums.size();
    int increment = size;
    while (increment >= 1) {
        increment = increment / 2;
        for (int i = increment; i < size; i++) {
            if (nums[i] < nums[i-increment]) {
                int  j = i, tmp = nums[j];
                j -= increment;
                while (j >= 0 && nums[j] > tmp) {
                    nums[j+increment] = nums[j];
                    j -= increment;
                }
                j += increment;
                nums[j] = tmp;
            }
        }
    }
}
}//shellsort

namespace QuickSort{
int partition(vector<int>& nums, int start, int end) {
    int low = start, high = end, mid = low  + (high - low) / 2;
    if (nums[low] > nums[high]) swap(nums[low], nums[high]);
    if (nums[mid] > nums[high]) swap(nums[mid], nums[high]);
    if (nums[mid] > nums[low] ) swap(nums[low], nums[mid]);
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) high--;
        swap(nums[low], nums[high]);
        while (low < high && nums[low] <= pivot) low++;
        swap(nums[low], nums[high]);
    }
    return low;
}

void quicksort(vector<int>& nums, int start, int end) {
    if (start >= end) return;
    int pivot = partition(nums, start, end);
    quicksort(nums, start, pivot - 1);
    quicksort(nums, pivot + 1, end);
}

void sort(vector<int>& nums) {
    int size = nums.size();
    quicksort(nums, 0, size - 1);
}
}//QuickSort

namespace HeapSort{
void Heapadjust(vector<int>& nums, int  start, int end) {
    int pos = start;
    for (int j = start * 2 + 1 ; j <= end; j = j * 2 + 1) {
        if (j < end && nums[j+1] > nums[j]) j++;
        if (nums[j] < nums[pos]) {
            break;
        }
        swap(nums[pos], nums[j]);
        pos = j;
    }
}

void sort(vector<int>& nums) {
    int size = nums.size();
    for (int i = size / 2; i >= 0; i--) {
        Heapadjust(nums, i, size - 1);
    }
    for (int i = size - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        Heapadjust(nums, 0, i - 1);
    }
}
}//HeapSort

namespace MergeSort{
void Merge(vector<int>& target, vector<int>& aux,
           int lstart, int rstart, int rend) {
    int pos = lstart, lend = rstart - 1, size = rend - lstart + 1;
    while (lstart <= lend && rstart <= rend) {
        aux[pos++] = target[lstart] > target[rstart] ? target[rstart++] : target[lstart++];
    }
    while (lstart <= lend) {
        aux[pos++] = target[lstart++];
    }
    while (rstart <= rend) {
        aux[pos++] = target[rstart++];
    }
    pos--;
    for (int i = 0; i < size; i++) {
        target[pos] = aux[pos];
        pos--;
    }
}
void Msort(vector<int>& nums, vector<int>& aux, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        Msort(nums, aux, start, mid);
        Msort(nums, aux, mid + 1, end);
        Merge(nums, aux, start, mid + 1, end);
    }
}
void sort(vector<int>& nums) {
    int size = nums.size();
    vector<int> aux(size, 0);
    Msort(nums, aux, 0, size - 1);
}
}//MergeSort

int main()
{
    std::vector<int> nums;
    for (int i = 0; i < 10000; i++) {
        nums.push_back(rand() % 10000);
    }
    vector<int> test(nums);

    HeapSort::sort(nums);
    std::sort(test.begin(), test.end());

    for (size_t i =  0; i < nums.size(); i++) {
        assert(nums[i] == test[i]);
        std::cout << nums[i] << " ";
        if (i % 100 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
