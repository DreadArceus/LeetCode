#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
};

ListNode* makeList(int n)
{
    ListNode* head = new ListNode();
    ListNode* tail = head;
    while(n--)
    {
        ListNode* next = new ListNode();
        int x = 0;
        cin >> x;
        next->val = x;
        tail->next = next;
        tail = next;
    }
    return head->next;
}

void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

ListNode* insertionSortLL(ListNode* head)
{
    if(head == NULL)
    {
        return head;
    }
    ListNode* actualHead = head;
    while(head->next)
    {
        ListNode *active = head->next;
        head->next = active->next;
        if(active->val <= actualHead->val)
        {
            active->next = actualHead;
            actualHead = active;
        }
        else
        {
            ListNode *loc = actualHead;
            while(loc != head && loc->next->val < active->val)
            {
                loc = loc->next;
            }
            active->next = loc->next;
            loc->next = active;
            if(head->next == active)
            {
                head = head->next;
            }
        }
    }
    return actualHead;
}

int main()
{
    int n = 0;
    cin >> n;
    ListNode* head = makeList(n);
    printList(insertionSortLL(head));
}