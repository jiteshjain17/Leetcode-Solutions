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
    ListNode* deleteDuplicates(ListNode* head) {
        
// O(n), O(n) solution using hashmap:        
        
//         if(head == NULL) return head;
//         map<int,int> mp;
//         ListNode *curr = head;
//         while(curr){
//             mp[curr->val]++;
//             curr = curr->next;
//         }
        
//         ListNode *dummy = new ListNode(-1);
//         ListNode *new_head = dummy;
        
//         for(auto it: mp){
//             if(it.second == 1){
//                 ListNode *curr1 = new ListNode(it.first);
//                 new_head->next = curr1;
//                 new_head = new_head->next;
//             }
//         }
//         return dummy->next;
        
        
// O(n), O(1) solution using two pointers:
        
        if(head == NULL) return head;
        ListNode *curr = head, *prev = NULL;
        
        while(curr and curr->next){
            if(curr->val == curr->next->val){
                while(curr->next != NULL and curr->val == curr->next->val){
                    curr = curr->next;
                }
                if(prev != NULL){
                    prev->next = curr->next;
                    curr = curr->next;
                }else{
                    head = curr->next;
                    curr = curr->next;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
