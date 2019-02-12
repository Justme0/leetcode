#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    return sortListHelper(head, getLen(head));
  }

  int getLen(ListNode* head) {
    int len = 0;
    for (; head != nullptr; head = head->next) {
      ++len;
    }

    return len;
  }

  ListNode* sortListHelper(ListNode* head, int len)
  {
    if (len <= 1) {
      return head;
    }

    int leftLen = len / 2;
    int rightLen = len - leftLen;
    ListNode* middle = advance(head, leftLen); // [head, middle) & [middle, tail)
    head = sortListHelper(head, leftLen);
    middle = sortListHelper(middle, rightLen);

    return merge(head, leftLen, middle, rightLen);
  }

  ListNode* advance(ListNode* head, int len) {
    for (int i = 0; i < len; ++i) {
      head = head->next;
    }

    return head;
  }

  ListNode* merge(ListNode* first, int firstLen, ListNode* second, int secondLen)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    int lenA = 0;
    int lenB = 0;

    while (lenA < firstLen && lenB < secondLen) {
      if (first->val <= second->val) {
        tail->next = first;

        first = first->next;
        ++lenA;
      } else {
        tail->next = second;

        second = second->next;
        ++lenB;
      }
      tail = tail->next;
    }

    if (lenA == firstLen) {
      tail->next = second;
    } else {
      ListNode* backA = advance(first, firstLen - lenA - 1);
      backA->next = tail->next;
      tail->next = first;
    }

    return dummy.next;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                                     return !isspace(ch);
                                     }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                      return !isspace(ch);
                      }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

ListNode* stringToListNode(string input) {
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode* dummyRoot = new ListNode(0);
  ListNode* ptr = dummyRoot;
  for(int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

string listNodeToString(ListNode* node) {
  if (node == nullptr) {
    return "[]";
  }

  string result;
  while (node) {
    result += to_string(node->val) + ", ";
    node = node->next;
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
  string line;
  while (getline(cin, line)) {
    // cout << line << endl;
    ListNode* head = stringToListNode(line);

    ListNode* ret = Solution().sortList(head);

    string out = listNodeToString(ret);
    cout << out << endl;
  }
  return 0;
}
