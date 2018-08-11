/// TOOK ME TWO BILLION TRIES 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL) return head;
        if (head->next == NULL) return head;
        if (head->next->next == NULL) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* temp_first = first->next->next;
        ListNode* temp_second = second->next->next;
        first->next = temp_first;
        second->next = temp_second;
        if(temp_second != NULL){
            while (temp_first->next != NULL && temp_second->next != NULL){
                temp_first->next = temp_second->next;
                temp_first = temp_first->next;
                temp_second->next = temp_first->next;
                temp_second = temp_second->next;
            }
        }
        temp_first->next = second;
        return head;

    }
};
