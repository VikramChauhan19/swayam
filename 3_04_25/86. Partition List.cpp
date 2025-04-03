
using namespace std;
   struct ListNode {
      int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
   };

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            if(!head || !head->next) return head;
            ListNode* dummy  = new ListNode(0);
            ListNode* dummy2  = new ListNode(0);
            ListNode* prev = dummy;
            ListNode* cur = head;
            ListNode* prev2= dummy2;
    
            while(cur){
                if(cur->val < x){
                    prev->next = cur;
                    prev = cur;
                    cur = cur->next;
                }else{
                    prev2->next = cur;
                    prev2 = cur;
                    cur = cur->next;
                }
            }
            prev2->next = nullptr;
            prev->next = dummy2->next;
            
            return dummy->next;
            
        }
    };