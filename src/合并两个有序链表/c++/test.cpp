#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL) {}
};

/*
时间复杂度:O(M+N)
空间复杂度：O（1）
思路：
创建一个dummy指向头，遍历两个链表，当l1<l2时，用p指向l1，l1下移，再次比较l1和l2，当l1>l2时，让p指向l2，相当于用p来不断的改变每个节点的指针指向
最后当剩余一个链表不为空时，因为是递增的，直接拼在p的后面。注意最后返回dummy->next
*/
ListNode * mergeTwoSortedList(ListNode *node1, ListNode *node2){
	if(node1 == NULL) return node2;
	if(node2 == NULL) return node1;

	ListNode *dummy = new ListNode(-1);
	ListNode *p = dummy;
	while( node1 != NULL && node2 != NULL ) {
		if(node1->val < node2->val) {
			p->next = node1;
			node1 = node1->next;
		}else{
			p->next = node2;
			node2 = node2->next;
		}
		p = p->next;
	}
	if(node1 != NULL) p->next = node1;
	if(node2 != NULL) p->next = node2;
	return dummy->next;
}

int main(){
	ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(6);
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

	ListNode *res = mergeTwoSortedList(node1,node4);
	while(res != NULL) {
		std::cout << res->val <<std::endl;
		res = res->next;
	}
	return 0;
}