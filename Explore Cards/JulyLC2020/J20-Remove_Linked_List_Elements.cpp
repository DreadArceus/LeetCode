#include <iostream>
#include "ListNode.h"
using namespace std;
int main()
{
  int n = 0, x = 0;
  cin >> n;
  ListNode *head = new ListNode;
  head->makeList(n);
  cin >> x;
  head->removeElements(x);
  head->printList();
}
