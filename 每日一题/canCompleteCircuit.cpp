/*
* @Author: wilson_t
* @Date:   2020-11-18 09:48:49
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-18 09:53:37
*/
/**
* 题目[中等]：
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
说明: 
如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。

示例 1:
输入:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。

示例 2:
输入:
gas  = [2,3,4]
cost = [3,4,3]
输出: -1
解释:
你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gas-station
 */
class MinQ {
private:
    queue<int> A;
    deque<int> B;
public:
    MinQ() {
    }
    void push(int val) {
        A.push(val);
        while(!B.empty() && val < B.back()) {
            B.pop_back();
        }
        B.push_back(val);
    }
    int min() {
        return B.front();
    }
    void pop() {
        int val = A.front();
        A.pop();
        if(val == B.front()) B.pop_front();
    }
    int size() {
        return A.size();
    }
};

//前缀和+最小队列
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(2 * n);
        for(int i = 0; i < n; ++i) {
            diff[i] = diff[i + n] = gas[i] - cost[i];
        }
        for(int i = 1; i < 2 * n; ++i) {
            diff[i] += diff[i - 1];
        }
        int pre = 0;
        MinQ minq;
        for(int i = 0; i < n; ++i) {
            minq.push(diff[i]);
        }
        for(int i = 0; i < n; ++i) {
            if(pre <= minq.min()) return i;
            pre = diff[i];
            minq.push(diff[n + i]);
        }
        return -1;
    }
};

//一次遍历
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
