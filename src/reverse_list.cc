

#include "utility.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    // last node
    if (head == nullptr || head->next == nullptr)
      return head;

    // recursively
    ListNode *p = reverseList(head->next);

    // flip operation
    head->next->next = head;
    head->next = nullptr;

    return p;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {

    auto *node = stringToListNode(line);

    auto *ret = sol.reverseList(node);

    prettyPrintLinkedList(ret);
  }

  return 0;
}