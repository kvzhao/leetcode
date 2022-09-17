#include "utility.hpp"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {

    if (head == nullptr)
      return false;
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {

      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        return true;
    }

    return false;
  }
};

ListNode *CreateCycle(ListNode *head, int pos) {
  ListNode *current = head;
  unordered_map<int, ListNode *> address;

  int count = 0;
  while (current->next) {
    address[count] = current;
    current = current->next;
    ++count;
  }

  // last one
  current->next = address[pos];

  return head;
}

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    ListNode *head = stringToListNode(line);
    getline(cin, line);
    int pos = stoi(line);

    head = CreateCycle(head, pos);

    cout << sol.hasCycle(head) << endl;
  }

  return 0;
}