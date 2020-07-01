/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-01 00:04:30
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-01 00:18:19
*/
/*********************************************************
* 题目[简单]：
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*********************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode dummyNode;
        ListNode* cur = &dummyNode;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        cur->next = (l1 == NULL ? l2 : l1);
        return dummyNode.next;
    }
};