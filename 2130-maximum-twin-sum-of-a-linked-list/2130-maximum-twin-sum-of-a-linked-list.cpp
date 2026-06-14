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
private:
    ListNode* reverse(ListNode *const tortoise){
        ListNode* end = tortoise;
        ListNode* n = tortoise->next;
    
        while(n != nullptr){
            ListNode* temp = n->next;
            n->next = end;
            end = n;
            n = temp;
        }
        return end;
    }
public:
    int pairSum(ListNode* head) {
        int ans{INT_MIN};
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare != nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        ListNode* end = reverse(tortoise);
        tortoise->next = nullptr;
        // cout << head->val << " " << tortoise->val << " " << end->val << endl;
        while(head != nullptr && end != nullptr){
            ans = max(ans, head->val + end->val);
            head = head->next;
            end = end->next;
        }
        return ans;
    }
};