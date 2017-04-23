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
    ListNode* Insert(ListNode* head,ListNode* node)
    {
        if(head == NULL)
            return node;
        
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur && cur->val < node->val)
        {
            prev = cur;
            cur = cur->next;
        }
        
        if(prev == NULL)
        {
            node->next = head;
            return node;
        }    
        else
        {
            prev->next = node;
            node->next = cur;
            return head;
        }
        
    }
    
    ListNode *insertionSortList(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
        	return head;
   		ListNode* newHead = NULL;
        ListNode* cur = head;
        
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = NULL;
            newHead = Insert(newHead,cur);
            cur = next;
        }
        return newHead;
    }
};