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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
// time and space: O(max(len(l1),len(l2)))
        
        if(l1 == NULL and l2 == NULL) return NULL;
        
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        ListNode *curr1 = l1, *curr2 = l2;
        
        while(curr1 and curr2){
            
            int sum = curr1->val + curr2->val + carry;
            ListNode *curr = new ListNode(sum%10);
            carry = sum/10;
            head->next = curr;
            // curr = curr->next;
            head = head->next;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
            
        }
        
        while(curr1){
            int sum = curr1->val + carry;
            ListNode *temp1 = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp1;
            head = head->next;
            curr1 = curr1->next;
        }
        
        while(curr2){
            int sum = curr2->val + carry;
            ListNode *temp2 = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp2;
            head = head->next;
            curr2 = curr2->next;
        }
        
        if(carry > 0){
            ListNode *last = new ListNode(carry);
            head->next = last;
        }
        return dummy->next;
    }
};
