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
    ListNode* sortList(ListNode* head) {
        
//         if(head == NULL) return NULL;
        
//         ListNode *curr = head;
//         vector<int> v;
//         while(curr){
//             v.push_back(curr->val);
//             curr = curr->next;
//         }
        
//         sort(v.begin(), v.end());
        
//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp = new ListNode(v[0]);
//         dummy->next = temp;
//         for(int i = 1; i<v.size(); i++){
//             temp->next = new ListNode(v[i]);
//             temp = temp->next;
//         }
//         return dummy->next;
        
        
        
        /* Using merge sort(divide and conquer) O(nlogn), O(1): */
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *temp = head, *slow = head, *fast = head;
        
        // dividing the list into 2 halves at mid.
        // head of first list = head, tail of first = temp.
        // head of second list = slow, tail of second = fast.
        while(fast != NULL and fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);
        
        return merge(left_side, right_side);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(l1 != NULL and l2 != NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1 != NULL){
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL){
            curr->next = l2;
            l2 = l2->next;
        }
        
        return dummy->next;
    }
};

// https://www.youtube.com/watch?v=pNTc1bM1z-4
