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
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumbhead=new ListNode(0);
        dumbhead->next=head;
        ListNode* end=dumbhead;
        
        while(n--) end=end->next;
        ListNode* start=dumbhead;
        while(end->next)
        {
            end=end->next;
            start=start->next;
        }
        start->next=start->next->next;
        return dumbhead->next;
    }
};