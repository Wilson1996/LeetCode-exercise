/*
* @Author: wilson_t
* @Date:   2020-10-29 15:39:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-29 15:39:57
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
