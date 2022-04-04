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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL) return head;

        
        // O(n), O(n) solution:
//         vector<int> v;
//         ListNode *curr = head;
//         while(curr){
//             v.push_back(curr->val);
//             curr = curr->next;
//         }
        
//         int i = 0, j = v.size()-1;
//         while(i<k and j>v.size()-k){
//             i++;
//             j--;
//         }
//         swap(v[i], v[j]);
        
//         ListNode *dummy = new ListNode(-1);
//         ListNode *nhead = dummy;
        
//         for(int i = 0; i<v.size(); i++){
//             nhead->next = new ListNode(v[i]);
//             nhead = nhead->next;
//         }
//         return dummy->next;
        
        
        
        // O(n), O(1) solution:
//         ListNode *curr = head;
//         int n = 0;
//         while(curr){
//             n++;
//             curr = curr->next;
//         }
        
//         ListNode *curr1 = head, *curr2 = head;
//         for(int i = 0; i<k-1; i++){
//             curr1 = curr1->next;
//         }
        
//         for(int i = 0; i<n-k; i++){
//             curr2 = curr2->next;
//         }
//         swap(curr1->val, curr2->val);
//         return head;
        
        
        // O(n), O(1) optimized using 2 pointers:
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while(--k){
            ptr1 = ptr1->next;
        }
        kth = ptr1;              // to mark this as kth node
        ptr1 = ptr1->next;
        
        // when ptr1 reaches the end, ptr2 will be on (n-k)th node
        while(ptr1){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        swap(kth->val, ptr2->val);
        return head;
    }
};
