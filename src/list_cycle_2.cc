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
private:
  ListNode *findIntersect(ListNode *head) {
    if (!head)
      return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow)
        return slow;
    }

    return nullptr;
  }

public:
  ListNode *detectCycle(ListNode *head) {

    ListNode *hNode = findIntersect(head);
    if (!hNode)
      return nullptr;

    ListNode *fNode = head;

    while (fNode != hNode) {
      fNode = fNode->next;
      hNode = hNode->next;
    }

    return fNode;
  }
};

void CreateCycle(ListNode *head, int pos) {
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

  return;
}

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {
    ListNode *head = stringToListNode(line);
    getline(cin, line);
    int pos = stoi(line);

    unordered_map<ListNode *, int> nodeToPos{{nullptr, -1}};
    int p = 0;
    ListNode *current = head;
    while (current->next) {
      nodeToPos[current] = p++;
      current = current->next;
    }

    CreateCycle(head, pos);

    ListNode *intersect = sol.detectCycle(head);
    cout << (nodeToPos.at(intersect) == pos) << endl;
  }

  return 0;
}