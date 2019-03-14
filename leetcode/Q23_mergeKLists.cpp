#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeList1(ListNode* l1, ListNode* l2) {
  ListNode* l3 = new ListNode(0);
  ListNode* p = l3;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      p->next = new ListNode(l1->val);
      l1 = l1->next;
    } else {
      p->next = new ListNode(l2->val);
      l2 = l2->next;
    }

    p = p->next;
  }

  if (l1) {
    p->next = l1;
  }

  if (l2) {
    p->next = l2;
  }

  return l3->next;
}


ListNode* mergeList(ListNode* l1, ListNode* l2) {
  ListNode* l3 = new ListNode(0);
  ListNode* p = l3;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      // p->next = new ListNode(l1->val);
      p->next = l1;
      l1 = l1->next;
    } else {
      // p->next = new ListNode(l2->val);
      p->next = l2;
      l2 = l2->next;
    }

    p = p->next;
  }

  if (l1) {
    p->next = l1;
  }

  if (l2) {
    p->next = l2;
  }

  return l3->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  if (lists.size() == 0) {
    return NULL;
  }

  // ListNode* res = new ListNode(0);

  /*
  ListNode* res = lists[0];
  for (int i = 1; i < lists.size(); ++i) {
    res = mergeList(res, lists[i]);

    // ListNode* p = res;
    // while (p) {
    //   cout << p->val << " ";
    //   p = p->next;
    // }
    // cout << endl;
  }

  // return res->next;
  return res;
  */

  int len = lists.size();
  while (len > 1) {
    int step = (len + 1) / 2;
    for (int i = 0; i < len / 2; ++i) {
      lists[i] = mergeList(lists[i], lists[i + step]);
    }
    len = (len + 1) / 2;
  }
  return lists[0];
}

int main() {
  ListNode* l1 = new ListNode(1);
  ListNode* p = l1;
  p->next = new ListNode(4);
  p = p->next;
  p->next = new ListNode(5);

  ListNode* l2 = new ListNode(1);
  p = l2;
  p->next = new ListNode(3);
  p = p->next;
  p->next = new ListNode(4);

  ListNode* l3 = new ListNode(2);
  p = l3;
  p->next = new ListNode(6);

  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  ListNode* res = mergeKLists(lists);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}
