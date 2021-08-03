/*
* @Author: wilson_t
* @Date:   2021-08-03 15:51:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-03 16:00:12
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void max_heapify(vector<int>& arr, int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void build_heap(vector<int>& arr) {
    int len = arr.size();
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
}

void heap_sort(vector<int>& arr) {
    int len = arr.size();
    //初始化，i从最后一个父节点开始调整
    build_heap(arr);
    // for(int x: arr) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
int main() {
    // vector<int> arr = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    vector<int> arr = {3, 5, 3, 0, 8, 6, 1, 5};
    heap_sort(arr);
    for (int i = 0; i < (int)arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}