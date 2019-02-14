#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// divide and conquer
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

    int leftLen = len / 2; // len>=2, leftLen>=1
    int rightLen = len - leftLen;
    ListNode* preMiddle = advance(head, leftLen - 1);
    ListNode* middle = preMiddle->next; // [head, middle) & [middle, tail)
    preMiddle->next = nullptr; // key: divide to two separated lists
    head = sortListHelper(head, leftLen);
    middle = sortListHelper(middle, rightLen);

    return merge(head, middle);
  }

  ListNode* advance(ListNode* head, int len) {
    for (int i = 0; i < len; ++i) {
      head = head->next;
    }

    return head;
  }

  ListNode* merge(ListNode* first, ListNode* second)
  {
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (first != nullptr && second != nullptr) {
      if (first->val <= second->val) {
        tail->next = first;
        first = first->next;
      } else {
        tail->next = second;
        second = second->next;
      }
      tail = tail->next;
    }

    if (first == nullptr) {
      tail->next = second;
    } else {
      tail->next = first;
    }

    return dummy.next;
  }
};

#ifdef sgi_stl_algo
class Solution {
public:
    ListNode* sortList(ListNode* head) {
      // Do nothing if the list has length 0 or 1.
      if (head == nullptr || head->next == nullptr) {
        return head;
      }

      ListNode* carry = nullptr;
      ListNode* tmp[64]{};
      ListNode** fill = tmp;
      ListNode** counter = nullptr;
      do
      {
        carry = head;
        head = head->next;
        carry->next = nullptr;
        //carry.splice(carry.begin(), *this, begin());
        // carry.size==1

        for(counter = tmp; counter != fill && nullptr != *counter; ++counter)
        {
          // This operation is stable: for equivalent elements in the two lists, the elements from *this shall always precede the elements from other
          // https://en.cppreference.com/w/cpp/container/list/merge
          // so not equal to carry.merge(*count)
          //carry = merge(carry, counter);

          // count.size>=1, carry.size>=1
          *counter = merge(*counter, carry);

          // count.size>=2, carry.size=0
          std::swap(carry, *counter);
          // count.size=0, carry.size>=2
        }

        // count.size=0, carry.size>=1
        std::swap(carry, *counter);
        // count.size>=1, carry.size=0
        if (counter == fill)
          ++fill;
      }
      while ( head != nullptr );

      for (counter = tmp + 1; counter != fill; ++counter)
        *counter = merge(*counter, *(counter - 1));
      return *(fill - 1);
    }

    ListNode* merge(ListNode*& first, ListNode*& second)
    {
      ListNode dummy(0);
      ListNode *tail = &dummy;

      int lenA = 0;
      int lenB = 0;

      while (first != nullptr && second != nullptr) {
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

      if (first == nullptr) {
        tail->next = second;
      } else {
        tail->next = first;
      }

      first = nullptr;
      second = nullptr;

      return dummy.next;
    }
};
#endif

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
