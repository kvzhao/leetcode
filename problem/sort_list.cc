#include "utility.hpp"
using namespace std;

class Solution {
private:
  ListNode *getMid(ListNode *head) {
    ListNode *slow = nullptr, *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow == nullptr ? head : slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    return mid;
  }

  ListNode *merge(ListNode *l1, ListNode *l2) {
    ListNode *ptr = new ListNode(0);
    ListNode *current = ptr;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        current->next = l1;
        l1 = l1->next;
      } else {
        current->next = l2;
        l2 = l2->next;
      }
      current = current->next;
    }

    if (l1) {
      current->next = l1;
      l1 = l1->next;
    }

    if (l2) {
      current->next = l2;
      l2 = l2->next;
    }

    return ptr->next;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);
    return merge(left, right);
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    ListNode *head = stringToListNode(line);
    prettyPrintLinkedList(sol.sortList(head));
  }

  return 0;
}