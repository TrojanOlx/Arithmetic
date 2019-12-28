// AddTwoNumbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* prt = head;
	int carry = 0;
	while (true)
	{
		if (l1 != NULL) {
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			carry += l2->val;
			l2 = l2->next;
		}
		prt->val = carry % 10;
		carry /= 10;
		if (l1 != NULL || l2 != NULL || carry != 0)
		{
			prt = (prt->next = new ListNode(0));
		}
		else
		{
			break;
		}
	}
	return head;
}
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	ListNode* result = nullptr, ** prev = &result;
	for (int carry = 0; l1 || l2 || carry;) {
		if (l1)
		{
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2) {
			carry += l2->val;
			l2 = l2->next;
		}
		*prev = new ListNode(carry % 10);
		prev = &((*prev)->next);
		carry /= 10;
	}
	return result;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode(0);
	ListNode* prt = head;
	int carry = 0;
	while (true)
	{
		carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;

		prt->val = carry % 10;
		carry /= 10;

		if (l1 != NULL || l2 != NULL || carry != 0)
		{
			prt = (prt->next = new ListNode(0));
		}
		else
		{
			break;
		}
	}
	return head;

}



int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* node = addTwoNumbers2(l1, l2);

	cout << "" << endl;
}

