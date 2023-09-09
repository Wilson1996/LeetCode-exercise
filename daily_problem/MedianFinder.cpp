/*
* @Author: wilson_t
* @Date:   2020-08-13 14:10:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-13 14:10:52
*/
/*********************************************************
* 题目[困难]：
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例：
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2

进阶:
如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*********************************************************/
class MedianFinder {
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int, vector<int>, less<int>> small;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }

    void addNum(int num) {
        if(size == 0) {
            big.push(num);
        } else if(size & 1) {
            int tmp = big.top();
            if(num > tmp) {
                big.pop();
                big.push(num);
                num = tmp;
            }
            small.push(num);
        } else {
            int tmp = small.top();
            if(num < tmp) {
                small.pop();
                small.push(num);
                num = tmp;
            }
            big.push(num);
        }
        ++size;
    }

    double findMedian() {
        if(size & 1) {
            return big.top();
        } else {
            return (double)(big.top() + small.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */