#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	if (fast == NULL) {
		return false;
	}
	do {
		assert(NULL != fast);	// leetcode oj don't include assert.h, you should comment assert
		if (fast->next == NULL) {
			return false;
		}
		fast = fast->next->next;
		assert(NULL != slow);
		slow = slow->next;
	} while (!(fast == NULL || fast == slow));
	return fast == slow;
}

int main() {
	struct ListNode n = { 0, &n };
	assert(hasCycle(&n));

	struct ListNode n3 = { 0, NULL };
	struct ListNode n2 = { 0, &n3 };
	struct ListNode n1 = { 0, &n2 };
	n3.next = &n2;
	assert(hasCycle(&n1));

	n.next = NULL;
	assert(!hasCycle(&n));

	return 0;
}
