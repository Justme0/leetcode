#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

/*
 * if meet, return the meet point;
 * otherwise return NULL
 */
struct ListNode *meetPoint(struct ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *fast = head;
	struct ListNode *slow = head;
	do {
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next->next;
		slow = slow->next;
	} while (!(fast == NULL || fast == slow));

	if (fast == slow) {
		return fast;
	} else {
		return NULL;
	}
}

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *pmeet = meetPoint(head);
	if (NULL == pmeet) {
		return NULL;
	}

	/*
	 * devide list to x, y, z (devide point is cycle point and meet point);
	 * when meeting, assume s is the number of slow pointer goes.
	 * 
	 * (0 < y < r and n >= 1)
	 * fast pointer: 2s = s + nr => s = nr
	 * s = x + y
	 * so x = (n-1)r + z
	 */
	for (; head != pmeet; head = head->next, pmeet = pmeet->next);
	return head;
}

int main() {
	struct ListNode *nil = NULL;
	assert(NULL == detectCycle(nil));

	struct ListNode n = { 0, &n };
	assert(&n == detectCycle(&n));

	struct ListNode n3 = { 0, NULL };
	struct ListNode n2 = { 0, &n3 };
	struct ListNode n1 = { 0, &n2 };
	n3.next = &n2;
	assert(&n2 == detectCycle(&n1));

	n.next = NULL;
	assert(NULL == detectCycle(&n));

	return 0;
}
