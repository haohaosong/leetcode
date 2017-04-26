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
    //ÅĞ¶ÏÊÇ·ñº¬ÓĞ»·
    ListNode* hasCycle(ListNode* head)
    {   
        ListNode* pFast = head;
        ListNode* pSlow = head;
        while(pFast && pFast->next)
        {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        
        	if(pFast == pSlow)
                return pFast;
        }
        
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        
    	ListNode* isHasCycle = hasCycle(head);
        if(isHasCycle == NULL)
            return NULL;
        
        ListNode* p1 = head;
        ListNode* p2 = isHasCycle;
        
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};