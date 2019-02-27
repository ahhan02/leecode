#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  ListNode* pre = dummy;

  while (pre->next && pre->next->next) {
    ListNode* cur = pre->next;
    ListNode* post = pre->next->next;

      pre->next = post;
      cur->next = post->next;
      post->next = cur;

      pre = pre->next->next;
  }

  return dummy->next;
}

int main() {
  ListNode* head = new ListNode(1);
  ListNode* p = head;
  p->next = new ListNode(2); p = p->next;
  p->next = new ListNode(3); p = p->next;
  p->next = new ListNode(4);

  p = head;

  ListNode* res = swapPairs(head);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}
