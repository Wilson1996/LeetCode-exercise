/*
* @Author: wilson_t
* @Date:   2020-10-05 20:38:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-05 20:40:27
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*************************************************************
* 题目[困难]：
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：
给你这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明：
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
*************************************************************/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* it = head;
        while(it != nullptr) {
            ++n;
            it = it->next;
        }
        int m = n / k;
        ListNode dummy(0);
        dummy.next = head;
        it = &dummy;
        ListNode* pre = nullptr, *cur = it->next, *tail = cur, *nxt;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < k; ++j) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            it->next = pre;
            it = tail;
            pre = tail;
            tail = cur;
        }
        it->next = cur;
        return dummy.next;
    }
};