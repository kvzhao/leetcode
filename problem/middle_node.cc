
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
  ListNode *middleNode(ListNode *head) {

    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {

      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }
};

int main() {

  Solution sol;
  string line;

  while (getline(cin, line)) {

    ListNode *root = stringToListNode(line);

    ListNode *mid = sol.middleNode(root);

    prettyPrintLinkedList(mid);
  }

  return 0;
}