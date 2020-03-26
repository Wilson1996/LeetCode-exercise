/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-26 12:00:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-26 12:01:37
*/
/*********************************************************
* 题目[简单]：
编写一个函数，检查输入的链表是否是回文的。

示例 1：
输入： 1->2
输出： false 

示例 2：
输入： 1->2->2->1
输出： true 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*********************************************************/
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> nums;
        ListNode* iter = head;
        while(iter != NULL)
        {
            nums.push_back(iter->val);
            iter = iter->next;
        }
        int len = nums.size();
        for(int i = 0; i < len / 2; ++i)
        {
            if(nums[i] != nums[len - 1 - i])
                return false;
        }
        return true;
    }
};