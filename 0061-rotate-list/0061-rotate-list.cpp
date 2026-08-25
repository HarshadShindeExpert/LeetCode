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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0 ;
        ListNode* start = head ;
        while (start != nullptr)
        {
            len ++ ;
            start = start -> next ;
        }
        if ( len == 0 ) return nullptr ;
        if ( len == 1) return head ;
        k = k % len  ;
        if(k == 0) return head ;
        ListNode* NewNode = new ListNode(0);
        ListNode* temp = NewNode ;
        start = temp ;

        for(int i=1 ; i<k ; i++)
        {
            ListNode* TempNode = new ListNode(0);
            temp -> next = TempNode ;
            temp = temp -> next ;
        }
        temp -> next = head ;
        temp = temp -> next ;
        int stop = len - k ;
        while( stop > 0)
        {
            stop -- ;
            temp = temp->next ;
        }

        head = start ;
        while(temp != nullptr )
        {
            start -> val = temp -> val ;
            temp = temp -> next ;
            start = start -> next ;
        }
        start = head ;
        len = len - 1 ; 
        while( len > 0)
        {
            start = start->next ;
            len -- ;
        }
        temp = start ;
        start = start -> next ;
        temp -> next = nullptr ;
        temp = start ;
        while(start != nullptr )
        {
            start = start -> next ;
            temp -> next = nullptr ;
            delete temp ;
            temp = start ;
        }
        return head ;


    }
};