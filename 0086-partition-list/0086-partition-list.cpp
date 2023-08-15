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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* ans = temp ,*back = temp;
        ListNode* next = head, *move = head;
        
        while(move != NULL && move->val < x){
            temp = next;
            next = next->next;
            back = move;
            move = move->next;
        }
        
        // cout << temp->val << " " << next->val << " : " << back->val << " " << move->val << endl;
        while(back != NULL && move!= NULL && next != NULL && temp != NULL){
            if(move->val >= x){
                back = move;
                move = move->next;
                continue;
            }
            
            ListNode* x = move;
            move = move->next;
            back->next = move;
            
            x->next = next;
            temp->next = x;
            temp = temp->next;
            
        }
        
        return ans->next;
    }
};