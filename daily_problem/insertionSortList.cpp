/*
* @Author: wilson_t
* @Date:   2020-11-20 10:55:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-20 11:06:28
*/

/**
* 题目[中等]：
对链表进行插入排序。

插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 
插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4

示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* it = head, *target;
        while(it->next != nullptr) {
            if(it->val <= it->next->val) {
                it = it->next;
                continue;
            }
            target = it->next;
            ListNode* now = &dummy;
            while(now->next->val < target->val) now = now->next;
            it->next = it->next->next;
            target->next = now->next;
            now->next = target;
        }
        return dummy.next;
    }
};