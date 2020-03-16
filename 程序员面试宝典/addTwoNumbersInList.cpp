/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-16 20:22:58
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-16 20:26:52
*/
/*************************************************************
* 题目[中等]：
给定两个用链表表示的整数，每个节点包含一个数位。
这些数位是反向存放的，也就是个位排在链表首部。
编写函数对这两个整数求和，并用链表形式返回结果。
 
示例：
输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912

[进阶]：假设这些数位是正向存放的，请再做一遍。
示例：
输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
*************************************************************/
#include <iostream>

using namespace std;

// Definition for singly - linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    friend ostream& operator<<(ostream& os, ListNode* head)
    {
        ListNode* iter = head;
        while(iter != NULL)
        {
            os << iter->val << "->";
            iter = iter->next;
        }
        os << "NULL" << endl;
        return os;
    }
};

class Solution
{
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        int x, y;
        ListNode* head = new ListNode(0);
        ListNode* pre = head;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1) {x = l1->val; l1 = l1->next;}
            else x = 0;
            if(l2) {y = l2->val; l2 = l2->next;}
            else y = 0;
            x += (y + carry);
            carry = x / 10;
            pre -> next = new ListNode(x % 10);
            pre = pre -> next;
        }
        if(carry != 0)
            pre -> next = new ListNode(carry);
        ListNode* res = head->next;
        delete head;
        return res;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}