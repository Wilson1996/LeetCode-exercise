/*
* @Author: wilson_t
* @Date:   2020-10-29 15:39:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-02 12:18:01
*/
#include <queue>
using namespace std;

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

class MaxQ {
private:
    queue<int> A;
    deque<int> B;
public:
    MaxQ() {
    }
    void push(int val) {
        A.push(val);
        while(!B.empty() && val > B.back()) {
            B.pop_back();
        }
        B.push_back(val);
    }
    int max() {
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
