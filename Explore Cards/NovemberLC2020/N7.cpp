//v1: Reverse the lists, do add with carry: Accepted
//v2: Memory abuse?
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

ListNode* addLists(ListNode* h1, ListNode* h2)
{
    ListNode* ansH = new ListNode;
    ListNode* ansT = ansH;

    return ansH;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;
    ListNode* h1 = makeList(n1);
    ListNode* h2 = makeList(n2);
    
    ListNode* ansHead = addLists(h1, h2);

    printList(ansHead);
}