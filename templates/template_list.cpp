#include <iostream>
#include <stack>

using namespace std;

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
    void deleteNode(ListNode* head)
    {
        while (head != NULL)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};