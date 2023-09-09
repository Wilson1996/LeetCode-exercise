/*
* @Author: Williss Taan
* @Date:   2019-08-28 15:07:16
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-24 15:08:11
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int RandomInRange(int start, int end) {
    srand((unsigned)time(NULL));
    return rand() % (end - start + 1) + start;
}

void Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int data[], int length, int start, int end) {
    if(data == NULL || length <= 0 || start < 0 || end >= length) {
        // throw new std::exception("Invalid Parameters.");
        throw exception();
        abort();
    }
    int index = RandomInRange(start, end);
    cout << "index: " << index << endl;
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; ++index) {
        if(data[index] < data[end]) {
            ++small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end) {
    if(start == end)
        return;
    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index - 1);
    if(index < end)
        QuickSort(data, length, index + 1, end);
}



//版本2 双路快排
void quickSort2(vector<int>& nums, int l, int r) {
    if(l >= r) return;
    int n = nums.size();
    int pivot = nums[l];
    int i = l, j = r;
    while(i < j) {
        while(i < j && nums[j] > pivot) --j;
        nums[i] = nums[j];
        while(i < j && nums[i] <= pivot) ++i;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quickSort2(nums, l, i - 1);
    quickSort2(nums, i + 1, r);
}

// 版本3 三路快排
void triSort(vector<int>& a, int low, int high) {
    if(low >= high) return;
    int key = a[low];
    int i = low, j = low;
    int k = high;
    while(i <= k) {
        if(a[i] < key) swap(a[i++], a[j++]);
        else if(a[i] > key) swap(a[i], a[k--]);
        else i++;
    }
    triSort(a, low, j);
    triSort(a, k + 1, high);
}



int main(int argc, char const* argv[]) {
    // int data[] = {5, 6, 7, 9, 1, 7, 3, 8, 8, 10};
    // // cout << Partition(data, 10, 0, 9) << endl;
    // QuickSort(data, 10, 0, 9);
    // for (int i = 0; i < 10; ++i) {
    //     cout << data[i] << ",";
    // }
    // cout << endl;
    vector<int> nums = {5, 6, 7, 9, 1, 7, 3, 8, 8, 10};
    triSort(nums, 0, nums.size() - 1);
    for(int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


