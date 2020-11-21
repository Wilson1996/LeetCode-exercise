/*
* @Author: wilson_t
* @Date:   2020-11-21 13:30:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-21 13:35:27
*/
/**
* 题目[中等]：
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
进阶：
你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

示例 3：
输入：head = []
输出：[]
 
提示：
链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//mergesort I
//recursive(from top to bottom)
class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSort(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMid(head);
        ListNode* lh = head, *rh = mid->next;
        mid->next = nullptr;
        lh = mergeSort(lh);
        rh = mergeSort(rh);
        return merge(lh, rh);
    }
    ListNode* merge(ListNode* lh, ListNode* rh) {
        ListNode dummy(-1);
        ListNode* it = &dummy;
        while(lh != nullptr || rh != nullptr) {
            if(lh == nullptr) {
                it->next = rh;
                it = it->next;
                rh = rh->next;
            } else if(rh == nullptr) {
                it->next = lh;
                it = it->next;
                lh = lh->next;
            } else {
                if(lh->val <= rh->val) {
                    it->next = lh;
                    it = it->next;
                    lh = lh->next;
                } else {
                    it->next = rh;
                    it = it->next;
                    rh = rh->next;
                }
            }
        }
        it->next = nullptr;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

//mergesort II
//none recursive(from bottom to top)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};


//quicksort
class Solution {
    ListNode* split(ListNode* head) {
        auto s1 = head, s2 = head, pre = head;
        while (s2 && s2->next) {
            pre = s1;
            s1 = s1->next;
            s2 = s2->next->next;
        }
        return s2 ? s1 : pre;
    }

    ListNode* Qsort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto preMid = split(head);
        const int x = preMid->val;

        ListNode small, *stail = &small;
        ListNode equal, *etail = &equal;
        ListNode large, *ltail = &large;

        auto p = head;
        while (p) {
            auto back = p->next;

            if (p->val < x) {
                stail->next = p;
                stail = p;
            } else if (p->val == x) {
                etail->next = p;
                etail = p;
            } else {
                ltail->next = p;
                ltail = p;
            }

            p = back;
        }

        stail->next = etail->next = ltail->next = nullptr;

        small.next = Qsort(small.next);
        large.next = Qsort(large.next);

        p = small.next;
        while (p && p->next) {
            p = p->next;
        }

        if (p) {
            p->next = equal.next;
        } else {
            small.next = equal.next;
        }

        etail->next = large.next;

        return small.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        return Qsort(head);
    }
};

