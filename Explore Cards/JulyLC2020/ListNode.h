#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

class ListNode
{
private:
  int val;
  ListNode *next;
public:
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
  void makeList(int n)
  {
    cin >> this->val;
    ListNode *previous = this;
    for(int i = 0; i < n - 1; i++)
    {
      ListNode *current = new ListNode;
      cin >> current->val;
      previous->next = current;
      previous = current;
    }
  }
  void removeElements(int x)
  {
    if(this->val == x)
    {
      if(this->next != NULL)
      {
        this->val = this->next->val;
        this->next = this->next->next;
      }
      else
      {
        exit(0);
      }
    }
    ListNode *previous = this;
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
  void printList()
  {
    cout << this->val << " ";
    ListNode *previous = this;
    while(previous->next != NULL)
    {
      ListNode *current = previous->next;
      cout << current->val << " ";
      previous = current;
    }
  }
};

#endif
