class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* current = head;

        while(current != nullptr)
        {
            count++;
            current = current->next;
        }

        if(n == count)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        int remove = count - n - 1;
        current = head;

        while(remove > 0)
        {
            current = current->next;
            remove--;
        }

        ListNode* del = current->next;
        current->next = del->next;
        delete del;

        return head;
    }
};