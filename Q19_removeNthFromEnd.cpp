#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* p = head;
  int len = 0;
  while (p) {
    len++;
    p = p->next;
  }
  // cout << "len: " << len << endl;

  int removeIdx = len - n;   // n
  if (removeIdx == 0) {
    head = head->next;
    return head;
  }

  ListNode *prev;

  p = head;
  int idx = 0;
  while (p) {
    if (idx == removeIdx) {
      prev->next = p->next;
      return head;
    } else {
      prev = p;
      p = p->next;
    }
    idx++;
  }

  return 0;
}

int main() {
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  p->next = new ListNode(2); p = p->next;
  p->next = new ListNode(3); p = p->next;
  p->next = new ListNode(4); p = p->next;
  p->next = new ListNode(5);
  ListNode *res = removeNthFromEnd(head, 2);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }
  return 0;
}

