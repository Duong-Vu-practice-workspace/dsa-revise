// Created by duongvct on 6/14/26.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeKthNode(ListNode* head, int k)
{
    if (k <= 0)
    {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* trailer = dummy;
    ListNode* leader = dummy;
    for (int i = 0; i < k; i++)
    {
        leader = leader->next;
        if (leader == nullptr)
        {
            return head;
        }
    }
    while (leader->next != nullptr)
    {
        leader = leader->next;
        trailer = trailer->next;

    }
    trailer->next = trailer->next->next;
    return dummy->next;


}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int k;
    cin >> k;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    ListNode* rev = removeKthNode(head, k);

    for (ListNode* p = rev; p != nullptr; p = p->next) {
        cout << p->val;
        if (p->next) cout << ' ';
    }
    cout << '\n';

    return 0;
}
