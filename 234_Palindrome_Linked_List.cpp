/*
234. Palindrome Linked List
Easy

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9 
Follow up: Could you do it in O(n) time and O(1) space?
*/
//Method 1
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
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp=head;
        return check(head);
    }
    bool check(ListNode* p){
        if(!p) return true;
        bool ispal= check(p->next) & (p->val==temp->val);
        temp=temp->next;
        return ispal; 
    }
};
//Method 2
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=Reverse(slow->next);
        slow=slow->next;
        fast=head;
        while(slow){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
    ListNode* Reverse(ListNode* head){
        ListNode* pre=NULL,*next=NULL;
        while(head){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        } 
        return pre;
    }
   
};
