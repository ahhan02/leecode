#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
  ListNode *p = l1, *q = l2;
  // ListNode *l3;
  ListNode *l3 = new ListNode(0);
  ListNode *r = l3;
  while (p && q) {
    if (p->val <= q->val) {
      // r = new ListNode(p->val);
      r->next = new ListNode(p->val);
      p = p->next;
    } else {
      // r = new ListNode(q->val);
      r->next = new ListNode(q->val);
      q = q->next;
    }

    // cout << "r->val: " << r->val << endl;

    r = r->next;
  }

  while (p) {
    // r = new ListNode(p->val);
    r->next = new ListNode(p->val);
    r = r->next;
    p = p->next;
  }

  while (q) {
    // r = new ListNode(q->val);
    r->next = new ListNode(q->val);
    r = r->next;
    q = q->next;
  }

  // return l3;
  return l3->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *p = l1, *q = l2;
  ListNode *l3 = new ListNode(0);
  ListNode *r = l3;

  while (p && q) {
    if (p->val <= q->val) {
      r->next = p;
      p = p->next;
    } else {
      r->next = q;
      q = q->next;
    }

    r = r->next;
  }

  /*
  while (p) {
    r->next = p;
    r = r->next;
  }

  while (q) {
    r->next = q;
    q = q->next;
  }
  */

  if (p) {
    r->next = p;
  }

  if (q) {
    r->next = q;
  }

  return l3->next;
}

int main() {
  ListNode *l1 = new ListNode(1);
  ListNode *p = l1;
  p->next = new ListNode(2); p = p->next;
  p->next = new ListNode(4);

  p = l1;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  ListNode *l2 = new ListNode(1);
  p = l2;
  p->next = new ListNode(3); p = p->next;
  p->next = new ListNode(4);

  p = l2;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  p = mergeTwoLists(l1, l2);
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
