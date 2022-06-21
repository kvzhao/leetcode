
#include "utility.hpp"
using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // recursive sol
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    if (list1->val < list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }

    return nullptr;
  }
};

int main() {
  string line;
  Solution sol;

  while (getline(cin, line)) {

    ListNode *list1 = stringToListNode(line);
    getline(cin, line);
    ListNode *list2 = stringToListNode(line);

    ListNode *ret = sol.mergeTwoLists(list1, list2);

    prettyPrintLinkedList(ret);
  }

  return 0;
}