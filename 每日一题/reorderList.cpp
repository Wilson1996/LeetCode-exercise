/*
* @Author: wilson_t
* @Date:   2020-10-20 10:17:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-20 10:17:45
*/
/*
* 题目[中等]：
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:
给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:
给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* it = head;
        vector<ListNode*> v;
        while(it) {
            v.emplace_back(it);
            it = it->next;
        }
        it = &dummy;
        int l = 0, r = v.size() - 1;
        while(l < r) {
            it->next = v[l];
            it = it->next;
            it->next = v[r];
            it = it->next;
            ++l;
            --r;
        }
        if(l == r) {
            it->next = v[l];
            it = it->next;
        }
        it->next = nullptr;
    }
};