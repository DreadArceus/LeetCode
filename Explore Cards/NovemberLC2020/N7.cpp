//v1: Reverse the lists, do add with carry: Accepted
//Not bad at all BUT the question says try to do it without modifying the input lists
//So naturally, thats coming up...
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

ListNode* reverseList(ListNode* h)
{
    if(h == NULL)
    {
        return h;
    }
    ListNode* after = h->next;
    h->next = NULL;
    ListNode* after2 = NULL;
    while(after)
    {
        after2 = after->next;
        after->next = h;
        h = after;
        after = after2;
    }
    return h;
}

ListNode* addLists(ListNode* h1, ListNode* h2)
{
    h1 = reverseList(h1);
    h2 = reverseList(h2);
    ListNode* ansH = new ListNode;
    ListNode* ansT = ansH;
    int carry = 0;
    while(h1 || h2)
    {
        int sum = ((h1) ? h1->val : 0) + ((h2) ? h2->val : 0);
        cout << sum << "\n";
        ListNode* ansNext = new ListNode;
        ansNext->val = (sum % 10 + carry) % 10;
        ansT->next = ansNext;
        ansT = ansNext;
        if(h1)
            h1 = h1->next;
        if(h2)
            h2 = h2->next;
        carry = (sum + carry) / 10;
    }
    if(carry != 0)
    {
        ansT->next = new ListNode;
        ansT->next->val = carry;
    }
    ansH = reverseList(ansH->next);
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