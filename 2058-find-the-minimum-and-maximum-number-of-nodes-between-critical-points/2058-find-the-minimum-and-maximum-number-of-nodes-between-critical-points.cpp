class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        ListNode* prev = head;
        ListNode* current = head->next;

        int pos = 1;
        int first = -1;
        int last = -1;
        int minimum = INT_MAX;

        while(current->next != nullptr)
        {
            if((current->val > prev->val && current->val > current->next->val) ||
               (current->val < prev->val && current->val < current->next->val))
            {
                if(first == -1)
                    first = pos;
                else
                    minimum = min(minimum, pos - last);

                last = pos;
            }

            prev = current;
            current = current->next;
            pos++;
        }

        if(first == -1 || first == last)
            return ans;

        ans[0] = minimum;
        ans[1] = last - first;

        return ans;
    }
};