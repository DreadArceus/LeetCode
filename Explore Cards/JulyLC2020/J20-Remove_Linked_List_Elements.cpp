#include <iostream>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
  {
    val = 0;
    next = NULL;
  }
  ListNode(int x)
  {
    val = x;
    next = NULL;
  }
  ListNode(int x, ListNode *next)
  {
    val = x;
    this->next = next;
  }
};
void makeList(ListNode *h, int n)
{
  cin >> h->val;
  ListNode *previous = h;
  for(int i = 0; i < n - 1; i++)
  {
    ListNode *current = new ListNode;
    cin >> current->val;
    previous->next = current;
    previous = current;
  }
}
void removeElements(ListNode *h, int x)
{
  ListNode *previous = h;
  while(previous->next != NULL)
  {
    ListNode *current = previous->next;
    if(current->val == x)
    {
      previous->next = current->next;
    }
    else
    {
      previous = current;
    }
  }
}
void printList(ListNode *h)
{
  cout << h->val << " ";
  ListNode *previous = h;
  while(previous->next != NULL)
  {
    ListNode *current = previous->next;
    cout << current->val << " ";
    previous = current;
  }
}
int main()
{
  int n = 0, x = 0;
  cin >> n;
  ListNode *head = new ListNode;
  makeList(head, n);
  cin >> x;
  if(head->val == x)
  {
    if(head->next != NULL)
    {
      head = head->next;
    }
    else
    {
      return 0;
    }
  }
  removeElements(head, x);
  printList(head);
}
