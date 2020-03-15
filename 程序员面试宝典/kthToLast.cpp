/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-15 13:32:09
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-15 13:40:32
*/
/*************************************************************
* 题目[简单]：
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
注意：本题相对原题稍作改动

示例：
输入： 1->2->3->4->5 和 k = 2
输出： 4

说明：
给定的 k 保证是有效的。
*************************************************************/
#include <iostream>

using namespace std;

// Definition for singly - linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    static int kthToLast(ListNode* head, int k)
    {
        ListNode* back = head;
        ListNode* front = head;
        for(int i = 0; i < k; ++i)
        {
            if(front != NULL)
                front = front->next;
            else
            {
                cout << "k is not valid!" << endl;
                return 0;
            }
        }
        while(front != NULL)
        {
            back = back->next;
            front = front->next;
        }
        return back->val;
    }
};

int main(int argc, char* argv[])
{
    ListNode nodes[5] = {1, 2, 3, 4, 5};
    ListNode* head = &nodes[0];
    for (int i = 1; i < 5; ++i)
    {
        nodes[i - 1].next = &nodes[i];
    }
    cout << Solution::kthToLast(head, 2) << endl;
}