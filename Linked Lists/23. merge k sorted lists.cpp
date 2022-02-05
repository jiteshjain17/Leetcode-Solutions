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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
// The basic idea is really simple. We can merge first two lists and then push it back. Keep doing this until there is only one list left in vector. Actually, we can regard this as an iterative divide-and-conquer solution.
        
        if(lists.empty()) return NULL;
        
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *curr1 = list1, *curr2 = list2;
        ListNode *dummy = new ListNode(INT_MIN);      // new always returns a pointer to node.
        ListNode *tail = dummy;
        
        while(curr1 and curr2){
            if(curr1->val < curr2->val){
                ListNode *temp = new ListNode(curr1->val);
                tail->next = temp;
                curr1 = curr1->next;
            }else{
                ListNode *temp = new ListNode(curr2->val);
                tail->next = temp;
                curr2 = curr2->next;
            }
            tail = tail->next;
        }
        tail->next = (curr1 != NULL) ? curr1 : curr2;   // if either of the lists is left
        return dummy->next;        
    }
};
