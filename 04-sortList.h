#pragma once

/*
* author:haohaosong
* date:2017/4/19
* note:链表的归并排序
*/

class Solution {
public:
	//找到中间的节点
	ListNode* findMiddleNode(ListNode* head)
	{
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		return slow;
	}

	//将两个有序的链表合成有序的一个链表
	ListNode* mergeTwoList(ListNode* phead1, ListNode* phead2)
	{
		if (phead1 == NULL)
			return phead2;
		if (phead2 == NULL)
			return phead1;

		ListNode* newHead = NULL;
		if (phead1->val < phead2->val)
			newHead = phead1;
		else
			newHead = phead2;

		ListNode* cur1 = phead1;
		ListNode* cur2 = phead2;
		ListNode* prev1 = NULL;
		ListNode* prev2 = NULL;

		while (cur1 && cur2)
		{
			while (cur1 && cur1->val < cur2->val)
			{
				prev1 = cur1;
				cur1 = cur1->next;
			}

			//判断头指向了1还是2
			if (prev1)
				prev1->next = cur2;

			//如果cur1为空，下面会崩溃
			if (cur1 == NULL)
				break;

			while (cur2 && cur2->val < cur1->val)
			{
				prev2 = cur2;
				cur2 = cur2->next;
			}

			prev2->next = cur1;
		}

		if (cur1 == NULL)
			prev1->next = cur2;
		else
			prev2->next = cur1;

		return newHead;
	}

	ListNode *sortList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* midNode = findMiddleNode(head);
		ListNode* midNext = midNode->next;
		midNode->next = NULL;

		ListNode* right = sortList(midNext);


		ListNode* left = sortList(head);

		return mergeTwoList(left, right);
	}
};