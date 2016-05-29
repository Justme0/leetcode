/*
   Merge k sorted linked lists and return it as one sorted list. Analyze and
   describe its complexity.
   */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  class Cmp {
  public:
    bool operator()(ListNode *pa, ListNode *pb) const {
      return pa->val > pb->val;
    }
  };

public:
  ListNode *mergeKLists(const std::vector<ListNode *> &lists) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    std::priority_queue<ListNode *, std::vector<ListNode *>, Cmp> Q;

    for (ListNode *pnode : lists) {
      if (nullptr != pnode) {
        Q.push(pnode);
      }
    }

    while (!Q.empty()) {
      tail->next = Q.top();
      Q.pop();
      if (nullptr != tail->next->next) {
        Q.push(tail->next->next);
      }
      tail = tail->next;
    }

    return dummy.next;
  }
};

void print(ListNode *L) {
  for (; nullptr != L; L = L->next) {
    std::cout << L->val << ' ';
  }
  std::cout << std::endl;
}

int main() {
  print(Solution().mergeKLists({nullptr}));
  ListNode a(0);
  ListNode b(0);
  ListNode c(1);
  ListNode d(2);
  c.next = &d;
  //print(Solution().mergeKLists({nullptr, &a, &b, &c}));

  return 0;
}
