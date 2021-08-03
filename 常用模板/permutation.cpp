/*
* @Author: wilson_t
* @Date:   2021-08-03 11:12:41
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-03 15:22:08
*/
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int>& v) {
    for(int x : v) cout << x << " ";
    cout << "\n";
}

bool my_next_permutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 1;
    for(; i > 0; --i) {
        if(nums[i] > nums[i - 1]) {
            break;
        }
    }
    if(i == 0) {
        sort(nums.begin(), nums.end());
        return false;
    }
    int cand = i;
    for(int j = i + 1; j < n; ++j) {
        if(nums[j] > nums[i - 1] && nums[j] <= nums[cand]) {
            cand = j;
        }
    }
    swap(nums[i - 1], nums[cand]);
    reverse(nums.begin() + i, nums.end());
    return true;
}


int main() {
    vector<int> v = {1, 2, 3};
    do {
        print(v);
    } while(next_permutation(v.begin(), v.end()));
    // } while(my_next_permutation(v));

    return 0;
}
