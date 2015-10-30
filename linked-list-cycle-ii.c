#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	if (fast == NULL) {
		return NULL;
	}
	do {
		assert(NULL != fast);
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next->next;
		assert(NULL != slow);
		slow = slow->next;
	} while (!(fast == NULL || fast == slow));
	if (fast == NULL) {
		return NULL;
	} else {
		return NULL;
	}
}

int main() {
	ListNode n = { 0, &n };
	assert(&n == detectCycle(&n));

	ListNode n3 = { 0, NULL };
	ListNode n2 = { 0, &n3 };
	ListNode n1 = { 0, &n2 };
	n3.next = &n2;
	assert(&n2 == detectCycle(&n1));

	return 0;
}
