#include <iostream>
using namespace std;

struct ListNode {
    int val;                // non-negative int
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);
    ListNode* l3_head = l3;
    ListNode* p;

    int carryFlag = 0;
    int sum;

    while (l1 && l2) {
      sum = l1->val + l2->val;

      if (carryFlag) {
        sum += 1;
        carryFlag = 0;
      }

      if (sum < 10) {
        p = new ListNode(sum); //l3->next = p; l3 = l3->next;
      } else {
        p = new ListNode(sum - 10); //l3->next = p; l3 = l3->next;
        carryFlag = 1;
      }

      // cout << "l3->val: " << l3->val << endl;

      l3->next = p;
      l3 = l3->next;

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      if (carryFlag) {
        sum = l1->val + 1;
        carryFlag = 0;
      } else {
        sum = l1->val;
      }

      if (sum < 10) {
        p = new ListNode(sum); //l3->next = p; l3 = l3->next;
      } else {
        p = new ListNode(sum - 10); //l3->next = p; l3 = l3->next;
        carryFlag = 1;
      }

      l3->next = p;
      l3 = l3->next;
      l1 = l1->next;
    }

    while (l2) {
      if (carryFlag) {
        sum = l2->val + 1;
        carryFlag = 0;
      } else {
        sum = l2->val;
      }

      if (sum < 10) {
        p = new ListNode(sum); //l3->next = p; l3 = l3->next;
      } else {
        p = new ListNode(sum - 10); //l3->next = p; l3 = l3->next;
        carryFlag = 1;
      }

      l3->next = p;
      l3 = l3->next;
      l2 = l2->next;
    }

    if (carryFlag) {
      p = new ListNode(1);
      l3->next = p;
    }

    return l3_head->next;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);
    ListNode* l3_head = l3;
    ListNode* p;

    int sum, remain, carry = 0;
    while (l1 || l2) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;
      // sum = l1->val + l2->val + carry;
      sum = val1 + val2 + carry;
      carry = sum / 10;
      remain = sum % 10;

      p = new ListNode(remain);
      l3->next = p;
      // cout << "l3->val: " << l3->val << " ";


      l3 = l3->next;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    if (carry) {
      p = new ListNode(1);
      l3->next = p;
    }

    return l3_head->next;
}


int main() {
//    ListNode* l1;
//    ListNode* l1_head = l1;
//    l1 = new ListNode(2);
//    cout << l1_head->val << endl;

    ListNode* l1 = new ListNode(2);
    ListNode* l1_head = l1;
    ListNode* p;

    p = new ListNode(4); l1->next = p; l1 = l1->next;
    p = new ListNode(3); l1->next = p;

    cout << "l1: ";
    p = l1_head;
    while (p) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;

    ListNode* l2 = new ListNode(5);
    ListNode* l2_head = l2;
    p = new ListNode(6); l2->next = p; l2 = l2->next;
    p = new ListNode(4); l2->next = p;

    cout << "l2: ";
    p = l2_head;
    while (p) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;

    // ListNode *res = addTwoNumbers(l1, l2);
    ListNode *res = addTwoNumbers(l1_head, l2_head);
    cout << "res: ";
    while (res) {
      cout << res->val << " ";
      res = res->next;
    }
    cout << endl;


    return 0;
}
