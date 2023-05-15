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
        ListNode* left = head;
        ListNode* right = head;
        ListNode* curr = head;
        
        int counter = 1;
        while(curr!=NULL){
            if (counter<k){
                left = left->next;
            }
            if (counter>k){
                right = right->next;
            }
            curr = curr->next;
            counter++;
        }
        //swap values
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        
        return head;
    }
};
// Idea of solution is to have two pointers: a left pointer and a right pointer
// Initialize both to the head, and a counter variable

// Left pointer:
// Iterate through the Linked list, and while the counter is less than k, increment the left pointer.
// After the counter greater than or equal to k, we do not want to move the left pointer anymore since it is in the desired position.

// Right pointer:
// The right pointer should not start moving until our counter exceeds k, this way the right pointer 'lags' behind the current pointer by k nodes.
// After counter exceeds k, we increment it each iteration together with the current pointer, keeping the k node lag

// After current reaches end of the list, we can swap the values in the left and right node to get our result

// Time Complexity: O(n)
// Space Complexity: O(1)