

   struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };
 
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) { //Tc = O(N) SC = O(1)
            if(!head || !head->next) return head;
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
            ListNode* cur = head;
            while (cur) { // time = O(N)
                if (cur->next && cur->val == cur->next->val) {
                    
                    while (cur->next && cur->val == cur->next->val) {
                        cur = cur->next;
                    }
                    prev->next = cur->next; // Removing all duplicates
                } else {
                    prev = cur; // Move prev forward if cur is unique
                }
                cur = cur->next; 
            }
            return dummy->next;
            
        }
    };