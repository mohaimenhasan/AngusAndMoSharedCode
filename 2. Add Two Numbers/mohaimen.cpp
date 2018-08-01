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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* l1_iter = l1;
            ListNode* l2_iter = l2;
            if (l1 == NULL && l2 == NULL)
                return NULL;
            else if (l2 == NULL) return l2;
            else if (l1 == NULL) return l2;
            ListNode* output = (ListNode*) malloc(sizeof(ListNode));
            ListNode* out_iter = output;
            // find the size
            // start with 1 as the while loop doesn't count the last element

            int size1 = 1;
            int size2 = 1;

            while (l1_iter->next != NULL){
              size1 ++;
              l1_iter = l1_iter->next;
            }

            while (l2_iter->next != NULL){
              size2 ++;
              l2_iter = l2_iter->next;
            }
            int holder = 0;

            // add upto the sizes are equal
            int smaller = 0;
            l1_iter = l1;
            l2_iter = l2;
            bool equal = false;
            bool size1Big = false;
            bool size2Big = false;
            if (size1 < size2){
              smaller = size1;
              size2Big = true;
              }
            else if (size2 < size1){
              smaller = size2;
              size1Big = true;
              }
            else{
              smaller = size1;
              equal = true;
            }
            for(int i = 0; i < smaller; i ++){
              int add = l1_iter->val + l2_iter->val + holder;
              if (add > 9){
                out_iter->val = add%10;
                holder = add/10;
              }
              else{
                out_iter->val = add;
                holder = 0;
              }
              if (i < smaller - 1){
                out_iter->next = (ListNode*) malloc(sizeof(ListNode));
                out_iter = out_iter->next;
              }
              l1_iter = l1_iter->next;
              l2_iter = l2_iter->next;
            }
            bool addedHolder = false;
            if (holder != 0){
              out_iter->next = (ListNode*) malloc(sizeof(ListNode));
              out_iter = out_iter->next;
              out_iter->val = holder;
              addedHolder = true;
            }

            if (equal)
              return output;

            else{
              for (int i = 0; i < abs(size1-size2); i++){
                if (addedHolder && i == 0){
                  if (size1Big){
                    out_iter->val += l1_iter->val;
                    l1_iter = l1_iter->next;
                  }
                  else{
                    out_iter->val += l2_iter->val;
                    l2_iter = l2_iter->next;
                  }
                }
                else{
                  out_iter->next = (ListNode*) malloc(sizeof(ListNode));
                  out_iter = out_iter->next;
                  out_iter->val = 0;
                  if (size1Big){
                    out_iter->val += l1_iter->val;
                    l1_iter = l1_iter->next;
                  }
                  else{
                    out_iter->val += l2_iter->val;
                    l2_iter = l2_iter->next;
                  }
                }

              }
            }
            return output;
        }
};
