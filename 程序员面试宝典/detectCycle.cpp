/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-18 10:04:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-18 10:11:06
*/
/************************************************************
* 题目[中等]：
给定一个有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？
*************************************************************/
#include <iostream>

using namespace std;

// Definition for singly - linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    //不能打印有环的链表
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
    static ListNode* detectCycle(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        ListNode* fast, *slow;
        fast = slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc, char* argv[])
{
    ListNode nodes[5] = {0, 1, 2, 3, 4};
    ListNode* head = &nodes[0];
    for(int i = 0; i < 4; ++i)
    {
        nodes[i].next = &nodes[i + 1];
    }
    nodes[4].next = &nodes[2];
    ListNode* res = Solution::detectCycle(head);
    if(res)
    {
        cout << res -> val << endl;
    }
    return 0;
}