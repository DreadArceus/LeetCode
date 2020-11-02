//Bitwise operations aside, the most optimal solution possible right here baby
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

ListNode* reverseList(ListNode* head)
{
    if(head->next == NULL)
    {
        return head;
    }
    ListNode* newHead = head->next;
    ListNode* temp = newHead->next;
    head->next = NULL;
    while(temp)
    {
        newHead->next = head;
        head = newHead;
        newHead = temp;
        temp = newHead->next;
    }
    newHead->next = head;
    return newHead;
}

int convert(ListNode* head)
{
    int num = 0, cnt = 0;
    while(head)
    {
        num += head->val * (int)__builtin_powf(2, cnt);
        cnt++;
        head = head->next;
    }
    return num;
}

int main()
{
    int n = 0;
    cin >> n;
    ListNode* head = reverseList(makeList(n));
    printList(head);
    int ans = convert(head);
    cout << ans;
}