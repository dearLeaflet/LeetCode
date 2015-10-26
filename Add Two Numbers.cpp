#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		
		while (l1 != NULL && l2 != NULL){
			int base = (l1->val + l2->val + carry) % 10;
			ListNode *q = new ListNode(base);
			p->next = q;
			p = q;
			carry = (l1->val + l2->val + carry) / 10;
			l1 = l1->next, l2 = l2->next;
		}
		if (l1 == NULL && l2 == NULL && carry > 0){
			p->next = new ListNode(carry);
		}
		if (l1 != NULL){
			p->next = l1;
			while (l1){
				int xx = l1->val;
				l1->val = (l1->val + carry) % 10;
				p = l1;
				carry = (xx + carry) / 10;
				l1 = l1->next;
			}
			if (carry > 0){
				p->next = new ListNode(carry);
			}
		}
		if (l2 != NULL){
			p->next = l2;
			while (l2){
				int xx = l2->val;
				l2->val = (xx + carry) % 10;
				p = l2;
				carry = (xx + carry) / 10;
				l2 = l2->next;
			}
			if (carry > 0){
				p->next = new ListNode(carry);
			}
		}
		/*p = head->next;
		head->next = NULL;
		ListNode *q;
		while (p){
			q = p->next;
			p->next = head->next;
			head->next = p;
			p = q;
		}*/
		
		return head->next;
	}
};
//class Solution1 {
//public:
//	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
//		ListNode head(-1);
//		int carry = 0;
//		ListNode *prev = &head;
//		for (ListNode *pa = l1, *pb = l2;
//			pa != nullptr || pb != nullptr;
//			pa = pa == nullptr ? nullptr : pa->next,
//			pb = pb == nullptr ? nullptr : pb->next,
//			prev = prev->next) {
//			const int ai = pa == nullptr ? 0 : pa->val;
//			const int bi = pb == nullptr ? 0 : pb->val;
//			const int value = (ai + bi + carry) % 10;
//			carry = (ai + bi + carry) / 10;
//			prev->next = new ListNode(value);
//		}
//		if (carry > 0)
//			prev->next = new ListNode(carry);
//		return head.next;
//	}
//};
//int main()
//{
//	ListNode *l2 = new ListNode(9);
//	ListNode *l1 = new ListNode(1);
//	l2->next = new ListNode(9);
//	//l1->next->next = new ListNode(9);
//	//l2->next = new ListNode(6);
//	//l1->next->next->next = new ListNode(9);
//	//l2->next->next = new ListNode(4);
//	Solution s;
//	ListNode *ls = s.addTwoNumbers(l1, l2);
//	while(ls != NULL){
//		cout << ls->val << ",";
//		ls = ls->next;
//	}
//	return 0;
//}