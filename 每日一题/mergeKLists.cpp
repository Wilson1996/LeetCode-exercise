/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-26 20:25:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-26 21:26:16
*/
/*********************************************************
* 题目[困难]：
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*********************************************************/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    bool operator<(const ListNode& rhs) const
    {
        return this->val < rhs.val;
    }
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

class GreaterCmp
{
public:
    bool operator()(const ListNode* lhs, const ListNode* rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution
{
public:
    void deleteNode(ListNode* head)
    {
        while (head != NULL)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int K = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, GreaterCmp> Q;
        for(int i = 0; i < K; ++i)
        {
            if(NULL != lists[i])
                Q.push(lists[i]);
        }
        ListNode dummyNode;
        ListNode* iter = &dummyNode;
        while(!Q.empty())
        {
            ListNode* cur = Q.top();
            Q.pop();
            iter->next = cur;
            iter = cur;
            if(cur->next != NULL)
                Q.push(cur->next);
        }
        return dummyNode.next;
    }
};

int main(int argc, char* argv[])
{
}