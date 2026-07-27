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
    ListNode* swapPairs(ListNode* head) {
        ListNode* start = head ;
        if(head == nullptr)
            return head ;
        while(head != nullptr && head->next != nullptr)
        {
            int temp = head->val ;
            head->val = head->next->val;
            head->next->val = temp ;
            head = head->next->next;
        }
        return start ;
        
    }
};