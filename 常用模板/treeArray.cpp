/*
* @Author: wilson_t
* @Date:   2020-08-11 21:23:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-28 13:35:49
*/
/*
* 树状数组
*/
// class Bit {
// private:
//     int n;
//     vector<int> a;
//     vector<int> c;
// public:
//     int lowbit(int x) {
//         return x & (-x);
//     }
//     Bit(vector<int>& nums) {
//         n = nums.size();
//         a = vector<int> (n + 1, 0);
//         c = vector<int> (n + 1, 0);
//         for(int i = 0; i < n; ++i) {
//             a[i + 1] = nums[i];
//         }
//         for(int i = 0; i < n; ++i) {
//             _update(i, nums[i]);
//         }
//     }
//     void _update(int i, int ins) {
//         ++i;
//         while(i <= n) {
//             c[i] += ins;
//             i += lowbit(i);
//         }
//     }
//     void update(int i, int val) {
//         ++i;
//         int ins = val - a[i];
//         a[i] = val;
//         while(i <= n) {
//             c[i] += ins;
//             i += lowbit(i);
//         }
//     }

//     int getSUm(int i) {
//         ++i;
//         int res = 0;
//         while(i > 0) {
//             res += c[i];
//             i -= lowbit(i);
//         }
//         return res;
//     }
//     int sumRange(int i, int j) {
//         return getSUm(j) - getSUm(i - 1);
//     }
// };





class Bit {
    vector<int> cv;
    int cn;
public:
    Bit(int size) : cn(size), cv(size+1, 0) {}

    int lowbit(int x){
        return x & (-x);
    }

    void update(int i, int x){
        while(i <= cn){
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += cv[i];
            i -= lowbit(i); 
        }
        return sum;
    }
};